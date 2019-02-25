# SpokeCalc CLI

#### A GNU/Linux command line application to quickly and accurately caclulate the correct spoke lengths when building a bicycle wheel.

## Installation

#### Install from PPA (Ubuntu/Debian)

Install key

```bash
sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com --recv-keys E0C69416

```
Add repository

```bash
sudo add-apt-repository ppa:elkriverweb/spokecalc

```

Update and install

```bash
sudo apt-get update && sudo apt-get install spokecalc

```
Run

```bash
spokecalc

```

#### Build Requirements

On Debian/Ubuntu

```bash
sudo apt install build-essential cmake devscripts debhelper

```

Clone the project's repository

``` bash
git clone https://elkriverweb@bitbucket.org/elkriverweb/spokecalc.git
```

Compile source from project root directory

```bash
mkdir build && cd build

```

```bash
cmake ..
```

```bash
make

```

## Usage

Run the executable from the project's source repository

```bash
./bin/spokecalc

```



