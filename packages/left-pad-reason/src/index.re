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
  "         "
|];

let leftPad (str: string) len character => {
  let nLen = ref (len - String.length str);
  let nChar =
    ref (
      if (0 == String.length character) {
        " "
      } else {
        character
      }
    );
  switch (!nChar, !nLen < 10) {
  | (" ", true) => cache.(!nLen) ^ str
  | _ =>
    let pad = ref "";
    let break = ref false;
    while (not !break) {
      switch (!nLen land 1, !nLen) {
      | (1, 0) =>
        pad := !pad ^ !nChar;
        break := true
      | (1, _) =>
        pad := !pad ^ !nChar;
        nLen := !nLen lsr 1;
        nChar := !nChar ^ !nChar
      | (_, 0) => break := true
      | (_, _) =>
        nLen := !nLen lsr 1;
        nChar := !nChar ^ !nChar
      }
    };
    !pad ^ str
  }
};
