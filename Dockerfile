# To build the container:
# docker build -t richi/conan:latest .
# To launch the container:
# docker run -it --rm --hostname conan --log-driver=journald richi/conan:latest

FROM opensuse:tumbleweed

MAINTAINER Richard Eigenmann

USER root

RUN zypper --non-interactive in \
  less \
  python3-pip \
  cmake \
  gcc6 gcc6-c++ \
  llvm-clang \
  libXrandr-devel openal-soft-devel flac-devel freetype-devel freetype2-devel libvorbis-devel libudev-devel libjpeg8-devel glew-devel freeglut-devel Mesa-devel \
  lcov \
  doxygen \
  xvfb-run \
  which \
  git;

#  sfml2-devel \


RUN pip install conan
RUN git clone https://github.com/richardeigenmann/SlidingTiles.git \
    && cd SlidingTiles \
    && git fetch \
    && git checkout conan \
    && mkdir -p build && cd build \
    && conan install ..\
    && cmake .. && make -j8 \
    && cd bin \
    && xvfb-run --server-args="-screen 0 1024x768x24" ./unit-tests

CMD  /bin/bash
