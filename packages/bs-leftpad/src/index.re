let cache = [|
  "",
  " ",
  "  ",
  "   ",
  "    ",
  "     ",
  "      ",
  "       ",
  "        ",
  "         ",
|];

let strFromCache = (str, len) =>
  switch (len) {
  | 0
  | 1
  | 2
  | 3
  | 4
  | 5
  | 6
  | 7
  | 8
  | 9 => cache[len] ++ str
  | _ => str
  };

let leftPad = (str, len, character) => {
  let nLen = ref(max(len - String.length(str), 0));
  let nChar =
    ref(
      if (0 == String.length(character)) {
        " ";
      } else {
        character;
      },
    );
  switch (nChar^, nLen^ < 10) {
  | (" ", true) => strFromCache(str, nLen^)
  | _ =>
    let pad = ref("");
    let break = ref(false);
    while (! break^) {
      switch (nLen^ land 1, nLen^) {
      | (1, 0) =>
        pad := pad^ ++ nChar^;
        break := true;
      | (1, _) =>
        pad := pad^ ++ nChar^;
        nLen := nLen^ lsr 1;
        nChar := nChar^ ++ nChar^;
      | (_, 0) => break := true
      | (_, _) =>
        nLen := nLen^ lsr 1;
        nChar := nChar^ ++ nChar^;
      };
    };
    pad^ ++ str;
  };
};
