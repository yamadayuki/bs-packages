open Jest;

open Expect;

open Humps;

describe
  "camelize"
  (
    fun () => {
      test
        "converts underscored strings to camelcase."
        (fun () => expect @@ camelize "hello_world" |> toBe "helloWorld");
      test
        "converts hyphenated strings to camelcase."
        (fun () => expect @@ camelize "hello-world" |> toBe "helloWorld");
      test
        "converts space-separated strings to camelcase."
        (fun () => expect @@ camelize "hello world" |> toBe "helloWorld");
      test
        "converts PascalCased strings to camelcase."
        (fun () => expect @@ camelize "HelloWorld" |> toBe "helloWorld");
      test "keeps numbers unchanged." (fun () => expect @@ camelize "-1" |> toBe "-1")
    }
  );

describe
  "decamelize"
  (
    fun () => {
      test
        "converts camelcased strings to underscored."
        (fun () => expect @@ decamelize "helloWorld" |> toBe "hello_world");
      test
        "does not separate on digits."
        (fun () => expect @@ decamelize "helloWorld1" |> toBe "hello_world1")
    }
  );
