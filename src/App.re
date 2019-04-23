let string = React.string;

[@react.component]
let make = () =>
  <div className="container-flex">
    <Header />
    <main role="main">
      <div className="album py-5 bg-light">
        <div className="container"> <ReposList /> </div>
      </div>
    </main>
  </div>;