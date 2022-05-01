# CMake Cookbook

<a href="https://www.packtpub.com/application-development/cmake-cookbook?utm_source=github&utm_medium=repository&utm_campaign=9781788470711 "><img src="https://d255esdrn735hr.cloudfront.net/sites/default/files/imagecache/ppv4_main_book_cover/B08515.png" alt="CMake Cookbook" height="256px" align="right"></a>

This is the code repository for [CMake Cookbook](https://www.packtpub.com/application-development/cmake-cookbook?utm_source=github&utm_medium=repository&utm_campaign=9781788470711), published by Packt.

**Building, testing, and packaging modular software with modern CMake**

## 配置环境

```shell
docker run -it devcafe/cmake-cookbook_ubuntu-18.0
pipenv install --three
pipenv run python testing/collect_tests.py 'chapter-*/recipe-*'
```

## 测试环境

示例在下列持续集成(CI)上进行过测试：

- Travis( https://travis-ci.org )用于 GNU/Linux 和 macOS
- Appveyor( https://www.appveyor.com )用于 Windows
- CircleCI ( https://circleci.com )用于附加的 GNU/Linux 测试和商业编译器

CI 服务的配置文件可以在示例库中找到( https://github.com/dev-cafe/cmake-cookbook/ ):

- Travis 的配置文件为 travis.yml
- Appveyor 的配置文件为.appveyor.yml
- CircleCI 的配置文件为.circleci/config.yml
- Travis 和 Appveyor 的其他安装脚本，可以在 testing/dependencies 文件夹中找到。

NOTE:GNU/Linux 系统上，Travis 使用 CMake 3.5.2 和 CMake 3.12.1 对实例进行测试。macOS 系统上用 CMake 3.12.1 进行测试。Appveyor 使用 CMake 3.11.3 进行测试。Circle 使用 CMake 3.12.1 进行测试。

测试机制是一组 Python 脚本，包含在 testing 文件夹中。脚本 collect_tests.py 将运行测试并报告它们的状态。示例也可以单独测试，也可以批量测试；collect_tests.py 接受正则表达式作为命令行输入，例如:

```shell
$ pipenv run python testing/collect_tests.py 'chapter-0[1,7]/recipe-0[1,2,5]'
```

该命令将对第 1 章和第 7 章的示例 1、2 和 5 进行测试。

要获得更详细的输出，可以设置环境变量 `VERBOSE_OUTPUT=ON` ：

```shell
$ env VERBOSE_OUTPUT=ON pipenv run python testing/collect_tests.py 'chapter-*/recipe-*'
```

## What is this book about?

CMake is cross-platform, open-source software for managing the build process in a portable fashion. This book features a collection of recipes and building blocks with tips and techniques for working with CMake, CTest, CPack, and CDash.

This book covers the following exciting features:

- Configure, build, test, and install code projects using CMake
- Detect operating systems, processors, libraries, files, and programs for conditional compilation
- Increase the portability of your code
- Refactor a large codebase into modules with the help of CMake
- Build multi-language projects
- Know where and how to tweak CMake configuration files written by somebody else
- Package projects for distribution
- Port projects to CMake

If you feel this book is for you, get your [copy](https://www.amazon.com/dp/1788470710) today!

<a href="https://www.packtpub.com/?utm_source=github&utm_medium=banner&utm_campaign=GitHubBanner"><img src="https://raw.githubusercontent.com/PacktPublishing/GitHub/master/GitHub.png"
alt="https://www.packtpub.com/" border="5" /></a>

## Instructions and Navigations

All of the code is organized into folders. For example, Chapter02.

The code will look like the following:

```
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-01 LANGUAGES CXX)
add_executable(hello-world hello-world.cpp)
```

**Following is what you need for this book:**
If you are a software developer keen to manage build systems using CMake or would like to understand and modify CMake code written by others, this book is for you. A basic knowledge of C++, C, or Fortran is required to understand the topics covered in this book.

With the following software and hardware list you can run all code files present in the book (Chapter 1-15).

### Software and Hardware List

| Chapter | Software required                                                                                       | OS required                        |
| ------- | ------------------------------------------------------------------------------------------------------- | ---------------------------------- |
| 1-15    | CMake >= 3.5 g++ supporting C++11 gcc supporting C99 gfortran Windows: msys2 installer or Visual Studio | Windows, Mac OS X, and Linux (Any) |
| 2       | Eigen 3.3.4                                                                                             | Windows, Mac OS X, and Linux (Any) |
| 3       | Python interpreter Python development libraries: BLAS LAPACK MPI library Eigen 3.3.4 Boost 1.59 ZeroMQ  | Windows, Mac OS X, and Linux (Any) |
| 4       | Boost 1.54 Catch2 Google Test                                                                           | Windows, Mac OS X, and Linux (Any) |
| 5       | Python interpreter Python development libraries BLAS LAPACK                                             | Windows, Mac OS X, and Linux (Any) |
| 6       | Python interpreter git                                                                                  | Windows, Mac OS X, and Linux (Any) |
| 8       | Boost 1.54 FFTW3 Eigen 3.3.4                                                                            | Windows, Mac OS X, and Linux (Any) |
| 9       | LAPACK                                                                                                  | Windows, Mac OS X, and Linux (Any) |
| 11      | CFFI Anaconda pybind11                                                                                  | Windows, Mac OS X, and Linux (Any) |
| 12      | Doxygen Sphinx Breathe                                                                                  | Windows, Mac OS X, and Linux (Any) |
| 13      | MXE Visual Studio                                                                                       | Windows, Mac OS X, and Linux (Any) |
| 14      | CDash                                                                                                   | Windows, Mac OS X, and Linux (Any) |

We also provide a PDF file that has color images of the screenshots/diagrams used in this book. [Click here to download it](https://www.packtpub.com/sites/default/files/downloads/CMakeCookbook_ColorImages.pdf).

## Get to Know the Author

**Radovan Bast** works at the High Performance Computing Group at UiT - The Arctic University of Norway in Tromsø and leads the CodeRefinery project. He has a PhD in theoretical chemistry and contributes to a number of quantum chemistry programs as a code developer. He enjoys learning new programming languages and techniques, and teaching programming to students and researchers. He got in touch with CMake in 2008 and has ported a number of research codes and migrated a number of communities to CMake since then.

**Roberto Di Remigio** is a postdoctoral fellow in theoretical chemistry at UiT - The Arctic University of Norway in Tromsø, Norway and Virginia Tech, USA. He is currently working on stochastic methods and solvation models. He is a developer of the PCMSolver library and the Psi4 open source quantum chemistry program. He contributes or has contributed to the development of popular quantum chemistry codes and libraries: DIRAC, MRCPP, DALTON, LSDALTON, XCFun, and ReSpect. He usually programs in C++ and Fortran.

### Suggestions and Feedback

[Click here](https://docs.google.com/forms/d/e/1FAIpQLSdy7dATC6QmEL81FIUuymZ0Wy9vH1jHkvpY57OiMeKGqib_Ow/viewform) if you have any feedback or suggestions.
