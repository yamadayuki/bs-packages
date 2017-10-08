# bs-humps

humps bindings for [BuckleScript](https://github.com/bloomberg/bucklescript) in [Reason](https://github.com/facebook/reason).

# Installation
1. install bs-humps

```sh
$ yarn add bs-humps

# or
$ npm install --save bs-humps
```

2. Add 'bs-humps' to 'bs-dependencies' section of `bsconfig.json` .

# Usage

Converting strings
```ml
Humps.camelize "hello_world"
(* => helloWorld *)

Humps.decamelize "fooBar"
(* => foo_bar *)

Humps.decamelizeWithOptions "hooBarBaz" @@ Humps.makeOptions separator::"-" ()
(* => foo-bar-baz *)
```

# Development
Build this project.
```
$ yarn build
```

Build this project with incremental build.
```
$ yarn watch
```

Run test.
```
$ yarn test
```

# Todo

- [ ] Implement external function definitions for `**Keys(object, options)` API.
