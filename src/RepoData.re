type owner = string;

type repo = {
  id: int,
  name: string,
  description: option(string),
  stargazers_count: int,
  html_url: string,
  user: owner,
};

let parseGithubOwner = json => Json.Decode.(json |> field("login", string));

let parseRepo = json =>
  Json.Decode.{
    id: json |> field("id", int),
    name: json |> field("name", string),
    description: json |> field("description", optional(string)),
    stargazers_count: json |> field("stargazers_count", int),
    html_url: json |> field("html_url", string),
    user: json |> field("owner", parseGithubOwner),
  };

let parseGithubResponse = json =>
  Json.Decode.(json |> field("items", array(parseRepo)));

let reposUrl = "https://api.github.com/search/repositories?q=user%3Aandreagulp&type=Repositories";

let fetchRepos = () =>
  Js.Promise.(
    Bs_fetch.fetch(reposUrl)
    |> then_(Bs_fetch.Response.text)
    |> then_(jsonText =>
         resolve(parseGithubResponse(Js.Json.parseExn(jsonText)))
       )
  );