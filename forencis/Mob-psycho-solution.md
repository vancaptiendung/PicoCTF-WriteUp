## 🧩 Challenge: Extracting the Flag from an APK

### 🔍 Step 1 — Unzip the APK
First, extract the APK into a folder so we can inspect its files:

```bash
unzip mobpsycho.apk -d mobpsycho
```

---

### 🔎 Step 2 — Search file contents for keywords
I wanted to search the extracted files for any occurrence of the string `pico`, so I concatenated all files and piped to `grep`:


```bash
find . -type f -exec cat {} + | grep -n "pico"
```

If you prefer a faster search that skips binary files, use `grep` recursively:
```bash
grep -RIn --binary-files=without-match "pico" .
```

![grep search result](greppicomobpsycho.png)

No matches were found with that keyword, so I broadened the search.

---

### 🔎 Step 3 — Look for files with "flag" in their name
Next, I searched for filenames containing the substring `flag`:

```bash
find . -type f -iname "flag"
```

This revealed a promising file:

![flag file found](mobpsychoflagfile.png)

---

### 🧩 Step 4 — Inspect the file and decode the flag
Opening the file revealed a **hex string**. To reverse (decode) the hex into readable text, you can use:

```bash
# If the hex is a single long line in file.txt
cat file.txt | tr -d ' \n' | xxd -r -p

# Or, if you have the hex as text, for example:
echo -n "48656c6c6f" | xxd -r -p
```

Running the decode command produced the flag.

---

### 🧠 Key Takeaways
- Use `unzip` to explore APK contents.
- Use `find` + `grep` (or `grep -R`) to search for keywords in many files.
- File names often hint at useful artifacts (`flag`).
- Hex-encoded strings can be converted back to text with `xxd -r -p` (or `xxd -r` / `xxd -p` variants).

---

### ⏺️ Example summary (for your write-up header)
**Tools used:** `unzip`, `find`, `grep`, `xxd`  
**Result:** Located a file containing a hex string, decoded it to retrieve the flag.