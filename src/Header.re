let string = React.string;

[@react.component]
let make = () => {
  let (isNavVisible, setNavVisibility) = React.useState(() => false);

  let toggleNav = () => setNavVisibility(_prev => !isNavVisible);

  let collapse = isNavVisible ? "bg-dark" : "collapse bg-dark";

  <header>
    <div className=collapse id="navbarHeader">
      <div className="container">
        <div className="row">
          <div className="col-sm-8 col-md-7 py-4">
            <h4 className="text-white"> {"About" |> string} </h4>
            <p className="text-muted">
              {"Add some information about the album below, the author, or any other background context. Make it a few sentences long so folks can pick up some informative tidbits. Then, link them off to some social networking sites or contact information."
               |> string}
            </p>
          </div>
          <div className="col-sm-4 offset-md-1 py-4">
            <h4 className="text-white"> {"Contact" |> string} </h4>
            <ul className="list-unstyled">
              <li>
                <a href="#" className="text-white">
                  {"Follow on Twitter" |> string}
                </a>
              </li>
              <li>
                <a href="#" className="text-white">
                  {"Like on Facebook" |> string}
                </a>
              </li>
              <li>
                <a href="#" className="text-white"> {"Email me" |> string} </a>
              </li>
            </ul>
          </div>
        </div>
      </div>
    </div>
    <div className="navbar navbar-dark bg-dark shadow-sm">
      <div className="container d-flex justify-content-between">
        <a href="#" className="navbar-brand d-flex align-items-center">
          <svg
            xmlns="http://www.w3.org/2000/svg"
            width="20"
            height="20"
            fill="none"
            stroke="currentColor"
            strokeLinecap="round"
            strokeLinejoin="round"
            strokeWidth="2"
            ariaHidden=true
            className="mr-2"
            viewBox="0 0 24 24"
            focusable="false">
            <path
              d="M23 19a2 2 0 0 1-2 2H3a2 2 0 0 1-2-2V8a2 2 0 0 1 2-2h4l2-3h6l2 3h4a2 2 0 0 1 2 2z"
            />
            <circle cx="12" cy="13" r="4" />
          </svg>
          <strong> {"Album" |> string} </strong>
        </a>
        <button
          className="navbar-toggler"
          type_="button"
          //   dataToggle="collapse"
          //   dataTarget="#navbarHeader"
          ariaControls="navbarHeader"
          ariaExpanded=false
          onClick={_e => toggleNav()}
          ariaLabel="Toggle navigation">
          <span className="navbar-toggler-icon" />
        </button>
      </div>
    </div>
  </header>;
};