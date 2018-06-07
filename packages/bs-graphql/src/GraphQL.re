module Language = {
  type location = {
    .
    "line": int,
    "column": int,
  };

  type source = {
    .
    "body": string,
    "name": string,
    "locationOffset": location,
  };

  type astNode;
};

module Error = {
  type error = {
    .
    "message": string,
    "locations": Js.nullable(array(Language.location)),
    "nodes": Js.nullable(array(Language.astNode)),
    "source": Js.nullable(Language.source),
    "positions": Js.nullable(array(int)),
    "originalError": Js.nullable(Js.Exn.t),
  };
};

module Type = {
  type schema;
  type resolveInfo;
  type fieldResolver('source, 'context) =
    {
      .
      "source": 'source,
      "args": Js.Types.obj_val,
      "context": 'context,
      "info": resolveInfo,
    } =>
    Js.Types.obj_val;
};

module Execution = {
  type executionResult('dataObj) = {
    .
    "data": Js.t('dataObj),
    "errors": Js.Null.t(Js.Array.t(Error.error)),
  };

  type executionArgs(
    'rootObjType,
    'contextObjType,
    'variableValuesObjType,
    'resolverFunc,
  ) = {
    .
    "schema": Type.schema,
    "source": string,
    "rootValue": Js.null_undefined(Js.t('rootObjType)),
    "contextValue": Js.null_undefined(Js.t('contextObjType)),
    "variableValue": Js.null_undefined(Js.t('variableValuesObjType)),
    "operationName": Js.null_undefined(string),
    "fieldResolver": Js.null_undefined('resolverFunc),
  };
};

module Utilities = {
  [@bs.module "graphql"]
  external buildSchema : string => Type.schema = "buildSchema";
};

module Validation = {
  type validationConetxt;
};

[@bs.module "graphql"]
external graphql :
  Execution.executionArgs(
    'rootObjType,
    'contextObjType,
    'variableValuesObjType,
    'resolverFunc,
  ) =>
  Js.Promise.t(Execution.executionResult('a)) =
  "graphql";

let run =
    (
      ~rootValue=?,
      ~contextValue=?,
      ~variableValue=?,
      ~operationName=?,
      ~fieldResolver=?,
      schema,
      source,
    ) =>
  graphql({
    "schema": schema,
    "source": source,
    "rootValue": Js.Null_undefined.fromOption(rootValue),
    "contextValue": Js.Null_undefined.fromOption(contextValue),
    "variableValue": Js.Null_undefined.fromOption(variableValue),
    "operationName": Js.Null_undefined.fromOption(operationName),
    "fieldResolver": Js.Null_undefined.fromOption(fieldResolver),
  });
