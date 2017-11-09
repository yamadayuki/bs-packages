open Jest;
open Expect;

describe("sample", (
  fun () => {
    test("1 + 1", (fun () => expect(1 + 1) |> toBe(2)))
  }
))
