<h1 align="center">Push_swap</h1>

<div align="center">
  <h3>A little Sorting Algorithm written in C</h3>
</div>

<div align="center">
  <a href="https://github.com/joaopedrogiancolidev/42_ft_push_swap/stargazers">
    <img src="https://img.shields.io/github/stars/joaopedrogiancolidev/42_ft_push_swap?style=flat&color=33b2b6" alt="Stars">
  </a>
  <a href="https://github.com/joaopedrogiancolidev/42_ft_push_swap/network/members">
    <img src="https://img.shields.io/github/forks/joaopedrogiancolidev/42_ft_push_swap?style=flat&color=33b2b6" alt="Forks">
  </a>
  <a href="https://www.linkedin.com/in/jpgusp/">
    <img src="https://img.shields.io/badge/LinkedIn-João%20Pedro-blue?style=flat&logo=linkedin" alt="LinkedIn">
  </a>
  <img src="https://img.shields.io/github/languages/top/joaopedrogiancolidev/42_ft_push_swap?style=flat&color=33b2b6" alt="Top Language">
  <img src="https://img.shields.io/github/languages/count/joaopedrogiancolidev/42_ft_push_swap?style=flat&color=33b2b6" alt="Language Count">
  <img src="https://img.shields.io/github/last-commit/joaopedrogiancolidev/42_ft_push_swap?style=flat&color=33b2b6" alt="Last Commit">
</div>

---

## 📚 Table of Contents
* [🚀 Getting Started](#-getting-started)
* [💡 About Push_swap](#-about-push_swap)
* [✨ Algorithm](#-algorithm)
* [📄 Evaluation](#-evaluation)
* [📞 Contact](#-contact)

---

## 🚀 Getting Started
This project is part of the 42 school curriculum. It challenges you to sort data on a stack using a limited set of instructions, aiming for the lowest possible number of operations.

### 📋 Prerequisites
Ensure you have a C compiler (like `gcc`) and `make` installed on your system.
```bash
gcc --version
make --version
```
### ⚙️ Installation & Build

Follow these steps to get a local copy up and running:

1. Clone the repostory:
```bash
git clone git@github.com:joaopedrogiancolidev/42_ft_push_swap.git
```
2. Navigate to the directory:
```bash
cd 42_ft_push_swap
```
3. Compile th project:
```bash
make
```
### 🖥️ Usage

The program will output the list of instructions required to sort the given numbers.
```bash
./push_swap 3 2 5 1 4
```
To count the number of operations
```bash
./push_swap 3 2 5 1 4 | wc -l
```
### 💡 About Push_swap

The goal is to sort stack A in ascending order using an auxiliary stack B and a specific set of operations.

🕹️ Available Operations

| Command | Description |
| :--- | :--- |
| **sa / sb** | **Swap**: Interchange the first two elements of stack A or B. |
| **ss** | Execute `sa` and `sb` simultaneously. |
| **pa / pb** | **Push**: Move the top element from one stack to the other. |
| **ra / rb** | **Rotate**: Shift all elements up by one (the first becomes the last). |
| **rr** | Execute `ra` and `rb` simultaneously. |
| **rra / rrb** | **Reverse Rotate**: Shift all elements down by one (the last becomes the first). |
| **rrr** | Execute `rra` and `rrb` simultaneously. |

### ✨ Algorithm

Efficiency is key. The sorting strategy is adapted based on the quantity of input integers:

.  Small Stacks (3 to 5 numbers): A specialized sorting logic that identifies the smallest values and pushes them to stack B, then handles the remaining 3 values with optimal move-sets.

.  Large Stacks (100 to 500+ numbers): More sophisticated approaches like Radix Sort (sorting based on bitwise normalization) or Chunks/Mechanical Turk algorithms to minimize operations.

---

### 📄 Evaluation

The project is successful if it meets the following 42 standards:

    [x] All integers are correctly sorted in ascending order.

    [x] Total operations stay within the efficiency thresholds (e.g., < 700 for 100 numbers).

    [x] Code is written in accordance with the Norm (42 coding standard).

    [x] No memory leaks (checked via Valgrind).

---

### 📞 Contact

João Pedro Giancoli - [LinkedIn Profile](https://www.linkedin.com/in/jpgusp/)

















