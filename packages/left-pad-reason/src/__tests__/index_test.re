open Jest;

open Expect;

open Index;

describe
  "strFromCache"
  (
    fun () => {
      test "0" (fun () => expect @@ strFromCache "foo" 0 |> toBe "foo");
      test "1" (fun () => expect @@ strFromCache "foo" 1 |> toBe " foo");
      test "9" (fun () => expect @@ strFromCache "foo" 9 |> toBe "         foo");
      test "10" (fun () => expect @@ strFromCache "foo" 10 |> toBe "foo")
    }
  );

describe
  "leftPad"
  (
    fun () => {
      describe
        "empty letter"
        (
          fun () => {
            test "2" (fun () => expect @@ leftPad "foo" 2 "" |> toBe "foo");
            test "3" (fun () => expect @@ leftPad "foo" 3 "" |> toBe "foo");
            test "4" (fun () => expect @@ leftPad "foo" 4 "" |> toBe " foo");
            test "5" (fun () => expect @@ leftPad "foo" 5 "" |> toBe "  foo");
            test "6" (fun () => expect @@ leftPad "foo" 12 "" |> toBe "         foo");
            test "7" (fun () => expect @@ leftPad "foo" 13 "" |> toBe "          foo")
          }
        );
      describe
        "space"
        (
          fun () => {
            test "2" (fun () => expect @@ leftPad "foo" 2 " " |> toBe "foo");
            test "3" (fun () => expect @@ leftPad "foo" 3 " " |> toBe "foo");
            test "4" (fun () => expect @@ leftPad "foo" 4 " " |> toBe " foo");
            test "5" (fun () => expect @@ leftPad "foo" 5 " " |> toBe "  foo");
            test "6" (fun () => expect @@ leftPad "foo" 12 " " |> toBe "         foo");
            test "7" (fun () => expect @@ leftPad "foo" 13 " " |> toBe "          foo")
          }
        );
      describe
        "character"
        (
          fun () => {
            test "2" (fun () => expect @@ leftPad "foo" 2 "." |> toBe "foo");
            test "3" (fun () => expect @@ leftPad "foo" 3 "." |> toBe "foo");
            test "4" (fun () => expect @@ leftPad "foo" 4 "." |> toBe ".foo");
            test "5" (fun () => expect @@ leftPad "foo" 5 "." |> toBe "..foo");
            test "6" (fun () => expect @@ leftPad "foo" 12 "." |> toBe ".........foo");
            test "7" (fun () => expect @@ leftPad "foo" 13 "." |> toBe "..........foo")
          }
        )
    }
  );
