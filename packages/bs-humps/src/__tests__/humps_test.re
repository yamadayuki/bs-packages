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

describe
  "decamelizeWithOptions"
  (
    fun () => {
      test
        "decamelizes strings with custom separator."
        (
          fun () =>
            expect @@ decamelizeWithOptions "helloWorld" @@ makeOptions separator::"-" () |>
            toBe "hello-world"
        );
      test
        "uses a custom split regexp."
        (
          fun () =>
            expect @@
            decamelizeWithOptions "helloWorld1" @@ makeOptions split::[%re "/(?=[A-Z0-9])/"] () |>
            toBe "hello_world_1"
        )
    }
  );

describe
  "pascalize"
  (
    fun () => {
      test
        "converts underscored strings to PascalCase."
        (fun () => expect @@ pascalize "hello_world" |> toBe "HelloWorld");
      test
        "converts hyphenated strings to PascalCase."
        (fun () => expect @@ pascalize "hello-world" |> toBe "HelloWorld");
      test
        "converts space-separated strings to PascalCase."
        (fun () => expect @@ pascalize "hello world" |> toBe "HelloWorld")
    }
  );

describe
  "depascalize"
  (
    fun () => {
      test
        "converts camelcased strings to underscored."
        (fun () => expect @@ decamelize "HelloWorld" |> toBe "hello_world");
      test
        "does not separate on digits."
        (fun () => expect @@ decamelize "HelloWorld1" |> toBe "hello_world1")
    }
  );

describe
  "depascalizeWithOptions"
  (
    fun () => {
      test
        "decamelizes strings with custom separator."
        (
          fun () =>
            expect @@ depascalizeWithOptions "HelloWorld" @@ makeOptions separator::"-" () |>
            toBe "hello-world"
        );
      test
        "uses a custom split regexp."
        (
          fun () =>
            expect @@
            depascalizeWithOptions "HelloWorld1" @@ makeOptions split::[%re "/(?=[A-Z0-9])/"] () |>
            toBe "hello_world_1"
        )
    }
  );
