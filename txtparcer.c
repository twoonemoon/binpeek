#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

const char* decode_instruction(uint16_t opcode) {
   
    switch (opcode) {
        case 0x0000: return "nop";           // 0000000000000000
        case 0x0001: return "wait";          // 0000000000000001
        case 0x0002: return "reset";         // 0000000000000010
        case 0x0003: return "stop";          // 0000000000000011
        case 0x0008: return "rti";           // 0000000000001000
        case 0x0009: return "rts";            // 0000000000001001
        case 0x000C: return "ijmpu";         // 0000000000001100
    }
   
   
   
    // 16'b000000000001xxxx : // RTSR
    if ((opcode & 0xFFF0) == 0x0010) return "rtsr";
   
    // 16'b000000000010xxxx : // PUSHR
    if ((opcode & 0xFFF0) == 0x0020) return "pushr";
   
    // 16'b000000000011xxxx : // POPR
    if ((opcode & 0xFFF0) == 0x0030) return "popr";
   
    // 16'b00000000010xxxxx : // CMPL
    if ((opcode & 0xFFE0) == 0x0040) return "cmpl";
   
    // 16'b00000000011xxxxx : // SMOVL
    if ((opcode & 0xFFE0) == 0x0060) return "smovl";
   
    // 16'b000000001xxxxxxx : // SST
    if ((opcode & 0xFF80) == 0x0080) return "sst";
   
    // 16'b00000001xxxxxxxx : // TRAP
    if ((opcode & 0xFF00) == 0x0100) return "trap";
   
    // 16'b00000010000xxxxx : // NOT
    if ((opcode & 0xFFE0) == 0x0200) return "not";
   
    // 16'b00000010001xxxxx : // NEG
    if ((opcode & 0xFFE0) == 0x0220) return "neg";
   
    // 16'b000000100100xxxx : // SRF
    if ((opcode & 0xFFF0) == 0x0240) return "srf";
   
    // 16'b000000100101xxxx : // RSF
    if ((opcode & 0xFFF0) == 0x0250) return "rsf";
   
    // 16'b000000100110xxxx : // RSFR
    if ((opcode & 0xFFF0) == 0x0260) return "rsfr";
   
    // 16'b0000001001110xxx : // IJMPCX
    if ((opcode & 0xFFF8) == 0x0270) return "ijmp";
   
    // 16'b0000001001111xxx : // IJSRCX
    if ((opcode & 0xFFF8) == 0x0278) return "ijsr";
   
    // 16'b000000101xxxxxxx : // CST
    if ((opcode & 0xFF80) == 0x0280) return "cst";
   
    // 16'b00000011000xxxxx : // ADC
    if ((opcode & 0xFFE0) == 0x0300) return "adc";
   
    // 16'b00000011001xxxxx : // SBB
    if ((opcode & 0xFFE0) == 0x0320) return "sbb";
   
    // 16'b0000001101xxxxxx : // LDRZ
    if ((opcode & 0xFFC0) == 0x0340) return "ldrz";
   
    // 16'b00000011100xxxxx : // PUSH
    if ((opcode & 0xFFE0) == 0x0380) return "push";
   
    // 16'b00000011101xxxxx : // POP
    if ((opcode & 0xFFE0) == 0x03A0) return "pop";
   
    // 16'b0000001111000xxx : // PUSHC
    if ((opcode & 0xFFF8) == 0x03C0) return "pushc";
   
    // 16'b0000001111001xxx : // POPC
    if ((opcode & 0xFFF8) == 0x03C8) return "popc";
   
    // 16'b000001xxxxxxxxxx : // MOV
    if ((opcode & 0xFC00) == 0x0400) return "mov";
   
    // 16'b000010000xxxxxxx : // PUSHL (1-word)
    if ((opcode & 0xFF80) == 0x0800) return "pushl_short";
   
    // 16'b000010001xxxxxxx : // PUSHL (2-word)
    if ((opcode & 0xFF80) == 0x0880) return "pushl_long";
   
    // 16'b0000100100xxxxxx : // BIC
    if ((opcode & 0xFFC0) == 0x0900) return "bic";
   
    // 16'b0000100101xxxxxx : // BIS
    if ((opcode & 0xFFC0) == 0x0940) return "bis";
   
    // 16'b0000100110xxxxxx : // BTG
    if ((opcode & 0xFFC0) == 0x0980) return "btg";
   
    // 16'b0000100111xxxxxx : // BTT
    if ((opcode & 0xFFC0) == 0x09C0) return "btt";
   
    // 16'b000010100xxxxxxx : // LDR
    if ((opcode & 0xFF80) == 0x0A00) return "ldr";
   
    // 16'b0000101010xxxxxx : // JMP
    if ((opcode & 0xFFC0) == 0x0A80) return "jmp";
   
    // 16'b0000101011xxxxxx : // JSR
    if ((opcode & 0xFFC0) == 0x0AC0) return "jsr";
   
    // 16'b0000101100xxxxxx : // XBU, XBS
    if ((opcode & 0xFFC0) == 0x0B00) return "xbu";
   
    // 16'b00001011010xxxxx : // XWU, XWS
    if ((opcode & 0xFFE0) == 0x0B40) return "xwu";
   
    // 16'b00001011100xxxxx : // PUSHU
    if ((opcode & 0xFFE0) == 0x0B80) return "pushu";
   
    // 16'b00001011101xxxxx : // POPU
    if ((opcode & 0xFFE0) == 0x0BA0) return "popu";
   
    // 16'b00001011110xxxxx : // RRC
    if ((opcode & 0xFFE0) == 0x0BC0) return "rrc";
   
    // 16'b00001011111xxxxx : // RLC
    if ((opcode & 0xFFE0) == 0x0BE0) return "rlc";
   
    // 16'b00010xxxxxxxxxxx : // MTPR
    if ((opcode & 0xF800) == 0x1000) return "mtpr";
   
    // 16'b00011xxxxxxxxxxx : // MFPR
    if ((opcode & 0xF800) == 0x1800) return "mfpr";
   
    // 16'b0010000xxxxxxxxx : // BEV
    if ((opcode & 0xFC00) == 0x2000) return "bev";
   
    // 16'b0010001xxxxxxxxx : // BOD
    if ((opcode & 0xFC00) == 0x2200) return "bod";
   
    // 16'b0010010xxxxxxxxx : // BNE
    if ((opcode & 0xFC00) == 0x2400) return "bne";
   
    // 16'b0010011xxxxxxxxx : // BEQ
    if ((opcode & 0xFC00) == 0x2600) return "beq";
   
    // 16'b0010100xxxxxxxxx : // BPL
    if ((opcode & 0xFC00) == 0x2800) return "bpl";
   
    // 16'b0010101xxxxxxxxx : // BMI
    if ((opcode & 0xFC00) == 0x2A00) return "bmi";
   
    // 16'b0010110xxxxxxxxx : // BNV
    if ((opcode & 0xFC00) == 0x2C00) return "bnv";
   
    // 16'b0010111xxxxxxxxx : // BOV
    if ((opcode & 0xFC00) == 0x2E00) return "bov";
   
    // 16'b0011000xxxxxxxxx : // BCC
    if ((opcode & 0xFC00) == 0x3000) return "bcc";
   
    // 16'b0011001xxxxxxxxx : // BCS
    if ((opcode & 0xFC00) == 0x3200) return "bcs";
   
    // 16'b0011010xxxxxxxxx : // BGE
    if ((opcode & 0xFC00) == 0x3400) return "bge";
   
    // 16'b0011011xxxxxxxxx : // BLT
    if ((opcode & 0xFC00) == 0x3600) return "btl";
   
    // 16'b0011100xxxxxxxxx : // BGT
    if ((opcode & 0xFC00) == 0x3800) return "bgt";
   
    // 16'b0011101xxxxxxxxx : // BLE
    if ((opcode & 0xFC00) == 0x3A00) return "ble";
   
    // 16'b0011110xxxxxxxxx : // BG
    if ((opcode & 0xFC00) == 0x3C00) return "bg";
   
    // 16'b0011111xxxxxxxxx : // BLQ
    if ((opcode & 0xFC00) == 0x3E00) return "blq";
   
    // 16'b010000xxxxxxxxxx : // MUL
    if ((opcode & 0xFC00) == 0x4000) return "mul";
   
    // 16'b010001xxxxxxxxxx : // MULS
    if ((opcode & 0xFC00) == 0x4400) return "muls";
   
    // 16'b010010xxxxxxxxxx : // ADD
    if ((opcode & 0xFC00) == 0x4800) return "add";
   
    // 16'b010011xxxxxxxxxx : // SUB
    if ((opcode & 0xFC00) == 0x4C00) return "sub";
   
    // 16'b010100xxxxxxxxxx : // CMP
    if ((opcode & 0xFC00) == 0x5000) return "cmp";
   
    // 16'b010101xxxxxxxxxx : // AND
    if ((opcode & 0xFC00) == 0x5400) return "and";
   
    // 16'b010110xxxxxxxxxx : // OR
    if ((opcode & 0xFC00) == 0x5800) return "or";
   
    // 16'b010111xxxxxxxxxx : // XOR
    if ((opcode & 0xFC00) == 0x5C00) return "xor";
   
    // 16'b011000xxxxxxxxxx : // SHL CONST
    if ((opcode & 0xFC00) == 0x6000) return "shl_const";
   
    // 16'b011001xxxxxxxxxx : // SHL SRC
    if ((opcode & 0xFC00) == 0x6400) return "shl_src";
   
    // 16'b011010xxxxxxxxxx : // SHR CONST
    if ((opcode & 0xFC00) == 0x6800) return "shr_const";
   
    // 16'b011011xxxxxxxxxx : // SHR SRC
    if ((opcode & 0xFC00) == 0x6C00) return "shr_src";
   
    // 16'b011100xxxxxxxxxx : // SHRA CONST
    if ((opcode & 0xFC00) == 0x7000) return "shra_const";
   
    // 16'b011101xxxxxxxxxx : // SHRA SRC
    if ((opcode & 0xFC00) == 0x7400) return "shra_src";
   
    // 16'b0111100xxxxxxxxx : // STA
    if ((opcode & 0xFE00) == 0x7800) return "sta";
   
    // 16'b0111101xxxxxxxxx : // LDA
    if ((opcode & 0xFE00) == 0x7A00) return "lda";
   
    // 16'b011111xxxxxxxxxx : // FLI
    if ((opcode & 0xFC00) == 0x7C00) return "fli";
   
    // 16'b100000xxxxxxxxxx : // DIVU
    if ((opcode & 0xFC00) == 0x8000) return "divu";
   
    // 16'b100001xxxxxxxxxx : // DIVS
    if ((opcode & 0xFC00) == 0x8400) return "divs";
   
    // 16'b100010xxxxxxxxxx : // LDS
    if ((opcode & 0xFC00) == 0x8800) return "lds";
   
    // 16'b100011xxxxxxxxxx : // STS
    if ((opcode & 0xFC00) == 0x8C00) return "sts";
   
    // 16'b1001000xxxxxxxxx : // LDDR
    if ((opcode & 0xFE00) == 0x9000) return "lddr";
   
    // 16'b1001001xxxxxxxxx : // STDR
    if ((opcode & 0xFE00) == 0x9200) return "stdr";
   
    // 16'b100101xxxxxxxxxx : // LDWRU, LDWRS
    if ((opcode & 0xFC00) == 0x9400) return "ldwr";
   
    // 16'b100110xxxxxxxxxx : // LDBRU, LDBRS
    if ((opcode & 0xFC00) == 0x9800) return "ldbr";
   
    // 16'b1001110xxxxxxxxx : // STWR
    if ((opcode & 0xFE00) == 0x9C00) return "stwr";
   
    // 16'b1001111xxxxxxxxx : // STBR
    if ((opcode & 0xFE00) == 0x9E00) return "stbr";
   
    // 16'b1010xxxxxxxxxxxx : // MOVL (1-word)
    if ((opcode & 0xF000) == 0xA000) return "movl_short";
   
    // 16'b1011xxxxxxxxxxxx : // MOVL (2-word)
    if ((opcode & 0xF000) == 0xB000) return "movl_long";
   
    // 16'b11000xxxxxxxxxxx : // ADDL (1-word)
    if ((opcode & 0xF800) == 0xC000) return "addl_short";
   
    // 16'b11001xxxxxxxxxxx : // ADDL (2-word)
    if ((opcode & 0xF800) == 0xC800) return "addl_long";
   
    // 16'b11010xxxxxxxxxxx : // SUBL (1-word)
    if ((opcode & 0xF800) == 0xD000) return "subl_short";
   
    // 16'b11011xxxxxxxxxxx : // SUBL (2-word)
    if ((opcode & 0xF800) == 0xD800) return "subl_long";
   
    // 16'b111000xxxxxxxxxx : // LDD, LDDO
    if ((opcode & 0xFC00) == 0xE000) return "ldd";
   
    // 16'b111001xxxxxxxxxx : // STD, STDO
    if ((opcode & 0xFC00) == 0xE400) return "std";
   
    // 16'b11101xxxxxxxxxxx : // LDWU, LDWOU, LDWS, LDWOS
    if ((opcode & 0xF800) == 0xE800) return "ldw";
   
    // 16'b11110xxxxxxxxxxx : // LDBU, LDBOU, LDBS, LDBOS
    if ((opcode & 0xF800) == 0xF000) return "ldb";
   
    // 16'b111110xxxxxxxxxx : // STW, STWO
    if ((opcode & 0xFC00) == 0xF800) return "stw";
   
    // 16'b111111xxxxxxxxxx : // STB, STBO
    if ((opcode & 0xFC00) == 0xFC00) return "stb";
   
    // 16'b0000110xxxxxxxxx : // BR
    if ((opcode & 0xFC00) == 0x0C00) return "br";
   
    // 16'b0000111xxxxxxxxx : // LOOP
    if ((opcode & 0xFC00) == 0x0E00) return "loop";
   
    return "unknown";
}

int main(int argc, char *argv[]) {
    FILE *fp_in, *fp_out;
    unsigned char buffer[4];
    size_t read_bytes;
   
    if (argc != 2) {
        printf("Usage: %s <binary_file>\n", argv[0]);
        return 1;
    }
   
    fp_in = fopen(argv[1], "rb");
    if (!fp_in) {
        perror("Error opening file");
        return 1;
    }
   
    fp_out = fopen("file_32_rom.txt", "w");
    printf("out_file - file_32_rom.txt\n");
    if (!fp_out) {
        perror("Error creating output file");
        fclose(fp_in);
        return 1;
    }
   
    int line_count = 0;
   
    // Читаем и обрабатываем файл по 4 байта (32 бита)
    while ((read_bytes = fread(buffer, 1, 4, fp_in)) == 4) {
        // Собираем 32-битное слово из байтов (little-endian)
        uint32_t word = (buffer[3] << 24) | (buffer[2] << 16) | (buffer[1] << 8) | buffer[0];
       
        // Извлекаем нижние 16 бит как опкод команды
        uint16_t opcode = word & 0xFFFF;
       
        // Декодируем команду
        const char* cmd = decode_instruction(opcode);
       
        // Форматируем вывод: шестнадцатеричное представление + команда
        fprintf(fp_out, "%02x%02x%02x%02x //%s\n",
                buffer[3], buffer[2], buffer[1], buffer[0], cmd);
       
        line_count++;
    }
   
    // Обработка неполного слова в конце файла
    if (read_bytes > 0) {
        uint32_t word = 0;
        // Собираем слово из оставшихся байтов
        for (int i = read_bytes - 1; i >= 0; --i) {
            word = (word << 8) | buffer[i];
        }
       
        // Выравниваем
        word = word << (8 * (4 - read_bytes));
       
        // Извлекаем опкод
        uint16_t opcode = word & 0xFFFF;
        const char* cmd = decode_instruction(opcode);
       
        // Выводим оставшиеся байты
        for (int i = read_bytes - 1; i >= 0; --i) {
            fprintf(fp_out, "%02x", buffer[i]);
        }
        // Добавляем пробелы для выравнивания
        for (int i = 0; i < 4 - read_bytes; i++) {
            fprintf(fp_out, "  ");
        }
        fprintf(fp_out, " // %s\n", cmd);
       
        line_count++;
    }
   
    printf("Processed %d lines\n", line_count);
   
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}

