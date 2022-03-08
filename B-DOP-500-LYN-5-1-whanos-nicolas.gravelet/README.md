<div id="top"></div>

<div align="center">

<h3 align="center">WHANOS</h3>

</div>

<!-- ABOUT THE PROJECT -->

## About The Project

As you might have guessed, Whanos is a powerful being, and wants you to set up an as-powerful Whanos infrastructure that allows any developer to automatically deploy an application into a cluster, just by a push to their Git repository.

### Requirements

1. Fetches the Git repository.
2. Analyses its content to determine its technology.
3. Containerizes the application into an image, based on both a Whanos image, and an eventual userprovided image customization.
4. Pushes the image into a Docker registry.
5. If a valid whanos.yml file exists, deploys the image into a cluster following the given configuration.

## Roadmap

What We implemented

- [x] Docker as the containerization technology;
- [x] Kubernetes as the clustering/orchestration technology;
- [x] Jenkins as the automation technology, linking the previous two.

### Built With

- [Groovy](https://groovy.apache.org/download.html/)
- [Dockerfile](https://docs.docker.com/engine/reference/builder/)
- [Shell](https://www.shellscript.sh/)


<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GETTING STARTED -->

## Getting Started

To get a local copy up and running follow these simple example steps.

### Prerequisites

- npm
  ```sh
  npm install npm@latest -g
  ```
- Typescript
  If you do not want to install typescript globally, install it as a dev dependency
  ```sh
   npm install typescript --save-dev
  ```

### Installation

1. Clone the repo
   ```sh
   git clone 
   ```
2. Enter the setup command
   ```sh
   
   ```
3. Enter the start command
   ```sh
   
   ```
4. Wait until it loads

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- ROADMAP -->

-

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- ROADMAP -->

## Full implementation

This implementation is not complete. Here are a few things I would add to this project.

- The...

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- CONTRIBUTING -->

## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- CONTACT -->

## Contact

Mahouve Charles - charles.mahouve@epitech.eu - [LinkedIn](https://www.linkedin.com/in/charles-mahouve-b50961165/)

Project Link: [Whanos](http.wwww.tofill.com)

<p align="right">(<a href="#top">back to top</a>)</p>

