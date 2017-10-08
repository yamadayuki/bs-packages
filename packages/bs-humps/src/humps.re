type options = Js.t {.};

external makeOptions : separator::string? => split::Js_re.t? => unit => options = "" [@@bs.obj];

external camelize : string => string = "camelize" [@@bs.module "humps"];

external decamelize : string => string = "decamelize" [@@bs.module "humps"];

external decamelizeWithOptions : string => options => string = "decamelize" [@@bs.module "humps"];
