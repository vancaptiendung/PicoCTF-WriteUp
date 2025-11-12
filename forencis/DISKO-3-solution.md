## 🧩 Challenge: Explore the Image

### 🔍 Step 1. Unzip and Inspect the Disk Image
After extracting the provided archive, I examined the disk file using `fdisk` to understand its structure:

```bash
fdisk -l disko-3.dd
```

The output showed **no additional partitions**, which means all file systems were stored **directly within the image**.

---

### 💽 Step 2. Mount the Disk Image
First, create a directory to mount the image:

```bash
sudo mkdir /mnt/disko3
```

Then, mount the image using the loop option:

```bash
sudo mount -o loop disko-3.dd /mnt/disko3
```

> **Note:**  
> The `-o loop` option attaches the image file to a **virtual loop device**, allowing it to be mounted as if it were a physical disk.

---

### 📂 Step 3. Explore the Mounted Filesystem
After mounting, navigate to the directory to explore its contents:

```bash
cd /mnt/disko3
ls
```

Inside, we can see several files and folders. Among them, one file stands out: **`flag.gz`**.

---

### 🏁 Step 4. Extract the Flag
Unzip the file to reveal the flag:

```bash
gunzip flag.gz
cat flag
```

✅ **Flag found!**

---

### 🧠 Key Takeaways
- Learned how to inspect and mount raw disk images using `fdisk` and `mount`.
- Understood how the `loop` device works for image mounting.
- Practiced extracting data from mounted forensic images to locate hidden files.

---