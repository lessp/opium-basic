open Opium.Std;

let hello_name =
  get("/hello/:name", req => {
    let person = param(req, "name");

    Lwt.return(Response.of_string_body(person));
  });

App.empty |> hello_name |> App.run_command;
