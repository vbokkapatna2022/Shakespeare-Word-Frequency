# Shakespeare Word Frequency (C++ + BRIDGES)

This C++ program uses the BRIDGES API to load a random Shakespeare work and display the top 10 most common words.

## Build
Requires BRIDGES headers and library installed locally (not included in repo).

```bash
g++ -std=c++11 -Ibridges/include -Ibridges/include/data_src shakespeare.cpp bridges/lib/libbridges.a -lcurl -o run


---

### **5️⃣ Init Git and commit**
```bash
git init
git add .
git commit -m "Initial commit: Shakespeare word frequency (clean version)"

git branch -M main
git remote add origin https://github.com/vbokkapatna2022/Shakespeare-Word-Frequency.git
git push -u origin main --force

