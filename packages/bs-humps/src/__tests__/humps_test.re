open Jest;

open Expect;

open Humps;

describe(
  "camelize",
  () => {
    test(
      "converts underscored strings to camelcase.",
      () => expect(camelize("hello_world")) |> toBe("helloWorld")
    );
    test(
      "converts hyphenated strings to camelcase.",
      () => expect(camelize("hello-world")) |> toBe("helloWorld")
    );
    test(
      "converts space-separated strings to camelcase.",
      () => expect(camelize("hello world")) |> toBe("helloWorld")
    );
    test(
      "converts PascalCased strings to camelcase.",
      () => expect(camelize("HelloWorld")) |> toBe("helloWorld")
    );
    test(
      "keeps numbers unchanged.",
      () => expect(camelize("-1")) |> toBe("-1")
    )
  }
);

describe(
  "decamelize",
  () => {
    test(
      "converts camelcased strings to underscored.",
      () => expect @@ decamelize("helloWorld") |> toBe("hello_world")
    );
    test(
      "does not separate on digits.",
      () => expect @@ decamelize("helloWorld1") |> toBe("hello_world1")
    )
  }
);

describe(
  "decamelizeWithOptions",
  () => {
    test(
      "decamelizes strings with custom separator.",
      () =>
        expect @@
        decamelizeWithOptions("helloWorld", makeOptions(~separator="-", ()))
        |> toBe("hello-world")
    );
    test(
      "uses a custom split regexp.",
      () =>
        expect @@
        decamelizeWithOptions(
          "helloWorld1",
          makeOptions(~split=[%re "/(?=[A-Z0-9])/"], ())
        )
        |> toBe("hello_world_1")
    )
  }
);

describe(
  "pascalize",
  () => {
    test(
      "converts underscored strings to PascalCase.",
      () => expect @@ pascalize("hello_world") |> toBe("HelloWorld")
    );
    test(
      "converts hyphenated strings to PascalCase.",
      () => expect @@ pascalize("hello-world") |> toBe("HelloWorld")
    );
    test(
      "converts space-separated strings to PascalCase.",
      () => expect @@ pascalize("hello world") |> toBe("HelloWorld")
    )
  }
);

describe(
  "depascalize",
  () => {
    test(
      "converts camelcased strings to underscored.",
      () => expect @@ decamelize("HelloWorld") |> toBe("hello_world")
    );
    test(
      "does not separate on digits.",
      () => expect @@ decamelize("HelloWorld1") |> toBe("hello_world1")
    )
  }
);

describe(
  "depascalizeWithOptions",
  () => {
    test(
      "decamelizes strings with custom separator.",
      () =>
        expect @@
        depascalizeWithOptions("HelloWorld", makeOptions(~separator="-", ()))
        |> toBe("hello-world")
    );
    test(
      "uses a custom split regexp.",
      () =>
        expect @@
        depascalizeWithOptions(
          "HelloWorld1",
          makeOptions(~split=[%re "/(?=[A-Z0-9])/"], ())
        )
        |> toBe("hello_world_1")
    )
  }
);
