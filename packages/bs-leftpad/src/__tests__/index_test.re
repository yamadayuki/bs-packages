open Jest;

open Expect;

open Index;

describe(
  "strFromCache",
  () => {
    test("0", () => expect(strFromCache("foo", 0)) |> toBe("foo"));
    test("1", () => expect(strFromCache("foo", 1)) |> toBe(" foo"));
    test("9", () => expect(strFromCache("foo", 9)) |> toBe("         foo"));
    test("10", () => expect(strFromCache("foo", 10)) |> toBe("foo"))
  }
);

describe(
  "leftPad",
  () => {
    describe(
      "empty letter",
      () => {
        test("2", () => expect(leftPad("foo", 2, "")) |> toBe("foo"));
        test("3", () => expect(leftPad("foo", 3, "")) |> toBe("foo"));
        test("4", () => expect(leftPad("foo", 4, "")) |> toBe(" foo"));
        test("5", () => expect(leftPad("foo", 5, "")) |> toBe("  foo"));
        test(
          "6",
          () => expect(leftPad("foo", 12, "")) |> toBe("         foo")
        );
        test(
          "7",
          () => expect(leftPad("foo", 13, "")) |> toBe("          foo")
        )
      }
    );
    describe(
      "space",
      () => {
        test("2", () => expect(leftPad("foo", 2, " ")) |> toBe("foo"));
        test("3", () => expect(leftPad("foo", 3, " ")) |> toBe("foo"));
        test("4", () => expect(leftPad("foo", 4, " ")) |> toBe(" foo"));
        test("5", () => expect(leftPad("foo", 5, " ")) |> toBe("  foo"));
        test(
          "6",
          () => expect(leftPad("foo", 12, " ")) |> toBe("         foo")
        );
        test(
          "7",
          () => expect(leftPad("foo", 13, " ")) |> toBe("          foo")
        )
      }
    );
    describe(
      "character",
      () => {
        test("2", () => expect(leftPad("foo", 2, ".")) |> toBe("foo"));
        test("3", () => expect(leftPad("foo", 3, ".")) |> toBe("foo"));
        test("4", () => expect(leftPad("foo", 4, ".")) |> toBe(".foo"));
        test("5", () => expect(leftPad("foo", 5, ".")) |> toBe("..foo"));
        test(
          "6",
          () => expect(leftPad("foo", 12, ".")) |> toBe(".........foo")
        );
        test(
          "7",
          () => expect(leftPad("foo", 13, ".")) |> toBe("..........foo")
        )
      }
    )
  }
);
