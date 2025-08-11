# Shakespeare Word Frequency (C++ + BRIDGES)

A small C++ program that uses the BRIDGES API to load a random Shakespeare work and print the **Top 10 most common words**.

## Requirements
- C++11 compiler (g++)
- BRIDGES C++ library (headers + static lib)
- libcurl (linked via -lcurl)
> Note: The BRIDGES SDK is not included in this repo. Place it locally (e.g., bridges/) or update the include/library paths below.

## Build
```bash
g++ -std=c++11 -Ibridges/include -Ibridges/include/data_src shakespeare.cpp bridges/lib/libbridges.a -lcurl -o run
```

## Run
```bash
./run
```

## Sample Output
```
Top 10 Most Common Words:
and : 640
the : 606
i : 519
to : 419
you : 391
of : 374
brutus : 366
that : 285
a : 267
not : 257
```

## Notes
- Replace your BRIDGES credentials in code with your own key; don’t commit real keys to GitHub.
- This repo intentionally excludes large SDK/data files to keep it lightweight for review.

