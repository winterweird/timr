# timr - A command line timer

This is just some stupid thing I made. Please don't take it too seriously.

**NOTE:** Relies on ANSI escape sequences for formatting, and uses `g++ -std=c++17`
for compilation.

## Installation

```
$ make
$ sudo make install
```

This will make the tools `untl` and `timr` and install them in /usr/bin/. You
can skip the last step if you'd like, or specify a different install path in the
makefile.

## Usage

```
$ timr 300      # timer for 300 seconds (five minutes)
$ timr 1 30     # timer for one minute and 30 seconds
$ timr 5 30 0   # timer for 5 hours, 30 minutes and 0 seconds

$ untl 2018-12-24 | timr             # timer going off on Christmas Eve 2018 at midnight
$ untl 2018-12-24 17:30::00 | timr   # timer going off on Christmas Eve 2018 at 5:30 PM

$ timr 45 00 && firefox https://www.youtube.com/watch?v=YwANQb4phH0 # play alarm after 45 minutes
```

**NOTE:** The `timr` tool is relatively robust in terms of input handling - it
should be able to give reasonable error messages on erroneous input.
**THE `untl` TOOL IS BRITTLE AND POORLY TESTED.** Please take care when 
specifying the input of this program. I make no guarantees for anything.
