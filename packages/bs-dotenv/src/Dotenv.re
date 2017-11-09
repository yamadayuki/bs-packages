let path = ".env";

let encoding = `utf8;

let matchRegexp = [%re "/^\\s*([\\w\\.\\-]+)\\s*=\\s*(.*)?\\s*$/"];

let parseLine = (line) =>
  Js.Re.exec(line, matchRegexp) |> (
    fun
    | Some(result) => {
        let captured = Js.Re.captures(result);
        [|captured[1], captured[2]|]
      }
    | None => [||]
  );

let parse = (src) => Js.String.split("\n", src);

let source = Node.Fs.readFileSync(path, encoding);
