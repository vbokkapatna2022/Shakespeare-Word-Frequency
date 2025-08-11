# 📖 Shakespeare Word Frequency (C++ + BRIDGES API) — by **Venu Bokkapatna**

This C++ program loads a random Shakespeare work via the BRIDGES API and prints the **Top 10 most common words**.

## ✅ Features
- 🎲 Randomly selects a Shakespeare play/poem from the dataset
- 🧹 Cleans words (lowercase + alphanumeric only)
- 📊 Counts word frequencies using a `map` and sorts by frequency (descending)
- 🔟 Displays the Top 10 most common words

## 🛠 Technologies Used
- C++11
- BRIDGES C++ API
- libcurl (for HTTP requests)

## ⚙️ How to Compile
```bash
g++ -std=c++11 -Ibridges/include -Ibridges/include/data_src shakespeare.cpp bridges/lib/libbridges.a -lcurl -o run
