let string = React.string;

[@react.component]
let make = (~repo: RepoData.repo) => {
  let repoDescription =
    switch (repo.description) {
    | Some(description) => description
    | None => "no description yet"
    };

  <div className="col-md-4">
    <div className="card mb-4 shadow-sm">
      //image

        <div className="card-body">
          <h5 className="card-title"> {repo.name |> string} </h5>
          <p className="card-text"> {repoDescription |> string} </p>
          <div className="d-flex justify-content-between align-items-center">
            <div className="btn-group">
              <button
                type_="button" className="btn btn-sm btn-outline-secondary">
                {"Open" |> string}
              </button>
              <a href={repo.html_url} target="_blank">
                <button
                  type_="button" className="btn btn-sm btn-outline-secondary">
                  {"View" |> string}
                </button>
              </a>
            </div>
            <small className="text-muted">
              {repo.stargazers_count |> string_of_int |> string}
            </small>
          </div>
        </div>
      </div>
  </div>;
};