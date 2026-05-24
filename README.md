# 🔍 binpeek
 
![C](https://img.shields.io/badge/C-99%2F11-lightgrey?style=flat-square) ![Platform](https://img.shields.io/badge/platform-linux%20%7C%20windows-lightgrey?style=flat-square)
 
---
 
## 🇷🇺 RU
 
Простая утилита для дизассемблирования бинарных файлов под кастомную 32-битную архитектуру. Читает файл по 4 байта (little-endian), декодирует нижние 16 бит как опкод и выдаёт текстовый файл с комментариями.
 
### ⚙️ Как работает
 
Читает бинарник пословно (32 бита), берёт младшие 16 бит — это опкод, декодирует его по таблице и пишет в `file_32_rom.txt` строки вида:
 
```
aabbccdd //mov
```
 
Поддерживает ~70 инструкций: `mov`, `add`, `sub`, `jmp`, `jsr`, `push`/`pop`, ветвления, сдвиги, загрузку/сохранение и прочее. Если опкод не распознан — пишет `unknown`.
 
### 🔧 Сборка
 
```bash
gcc -o binpeek txtparcer.c
```
 
### 🚀 Использование
 
```bash
./binpeek <binary_file>
```
 
Результат — файл `file_32_rom.txt` в текущей директории.
 
### ⚠️ Известные ограничения
 
- Выходной файл всегда называется `file_32_rom.txt`, путь не настраивается
- Двухсловные инструкции (`movl_long`, `addl_long` и т.д.) декодируются только по первому слову — второе слово (непосредственный операнд) идёт отдельной строкой
---
 
## 🇬🇧 EN
 
A small disassembler for a custom 32-bit ISA. Reads a binary file in 4-byte chunks (little-endian), decodes the lower 16 bits as an opcode, and writes a commented text file.
 
### ⚙️ How it works
 
Reads 32-bit words, extracts the low 16 bits as the opcode, matches it against a decode table, and outputs lines like:
 
```
aabbccdd //mov
```
 
Supports ~70 instructions: `mov`, `add`, `sub`, `jmp`, `jsr`, `push`/`pop`, branches, shifts, load/store and more. Unknown opcodes are marked `unknown`.
 
### 🔧 Build
 
```bash
gcc -o binpeek txtparcer.c
```
 
### 🚀 Usage
 
```bash
./binpeek <binary_file>
```
 
Output goes to `file_32_rom.txt` in the current directory.
 
### ⚠️ Known limitations
 
- Output filename is hardcoded to `file_32_rom.txt`
- Two-word instructions (`movl_long`, `addl_long`, etc.) are decoded only by the first word — the immediate operand word appears as a separate line
