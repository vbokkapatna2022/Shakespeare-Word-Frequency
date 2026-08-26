# Shakespeare Word Frequency

A C++ program that grabs a random Shakespeare work (play, poem, or sonnet) via the BRIDGES API and finds the 10 most frequently used words in it.

I built this to practice text processing in C++ — cleaning raw text, counting frequencies with a map, and writing my own sort instead of relying on a library function.

## What it does

- Pulls a randomly selected Shakespeare work from the BRIDGES dataset each run
- Cleans each word (strips punctuation, lowercases everything) before counting
- Counts word frequency using `std::map`, with recursion handling the traversal
- Sorts the results in descending order with a custom sort
- Prints the Top 10 most common words

## Built with

- C++11
- [BRIDGES C++ API](https://bridgesuncc.github.io/)
- libcurl (for the API's HTTP requests)

## How to compile and run

```bash
g++ -std=c++11 -Ibridges/include -Ibridges/include/data_src shakespeare.cpp bridges/lib/libbridges.a -lcurl -o run
./run
```

You'll need `libcurl` installed and the BRIDGES library set up in a `bridges/` folder alongside this file.

## Notes / things I'd improve

- Since it picks a random work each run, results aren't reproducible — could add a way to specify which work to load
- Common words like "the" and "and" dominate the list right now — filtering out stop words would surface more interesting results
