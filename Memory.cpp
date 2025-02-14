#include "Memory.h"

int Memory::getValue(int address) const {
    if(address < 1 || address > m_instructionTable.getTableRowCount())
        return 0;
    auto row = m_instructionTable.getRowByIndex(address - 1);
    return row[2] * 1000000 + row[3] * 1000 + row[4];
}

void Memory::setValue(int address, int value) {
    if (address >= 1 || address < m_instructionTable.getTableRowCount()) {
        int part1 = (value / 1000000) % 1000;
        int part2 = (value / 1000) % 1000;
        int part3 = value % 1000;
        m_instructionTable.setRowByIndex(address - 1, {0, part1, part2, part3});
    }
}
