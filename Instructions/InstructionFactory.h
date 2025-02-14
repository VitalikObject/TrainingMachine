#pragma once

#include <memory>
#include "AddInstruction.h"
#include "AssignmentInstruction.h"
#include "BranchInstruction.h"
#include "DivideInstruction.h"
#include "IInstruction.h"
#include "InputInstruction.h"
#include "JumpInstruction.h"
#include "ModuloInstruction.h"
#include "MultiplyInstruction.h"
#include "OutputInstruction.h"
#include "StopInstruction.h"
#include "SubtractInstruction.h"

class InstructionFactory {
public:
    static std::unique_ptr<IInstruction> createInstruction(const QList<int>& row) {
        int opCode = row[1];
        int arg1 = row[2];
        int arg2 = row[3];
        int arg3 = row[4];

        switch (opCode) {
        case 1:
        case 11:
            return std::make_unique<AddInstruction>(arg1, arg2, arg3);
        case 2:
        case 12:
            return std::make_unique<SubtractInstruction>(arg1, arg2, arg3);
        case 3:
        case 13:
            return std::make_unique<MultiplyInstruction>(arg1, arg2, arg3);
        case 4:
        case 14:
            return std::make_unique<DivideInstruction>(arg1, arg2, arg3);
        case 21:
            return std::make_unique<ModuloInstruction>(arg1, arg2, arg3);
        case 0:
            return std::make_unique<AssignmentInstruction>(arg1, arg3);
        case 10:
        case 20:
            return std::make_unique<AssignmentInstruction>(arg1, arg3);
        case 5:
        case 6:
            return std::make_unique<InputInstruction>(arg1, arg2);
        case 15:
        case 16:
            return std::make_unique<OutputInstruction>(arg1, arg2);
        case 9:
            return std::make_unique<JumpInstruction>(arg2);
        case 19:
            return std::make_unique<BranchInstruction>(arg1, arg2, arg3);
        case 31:
            return std::make_unique<StopInstruction>();
        default:
            throw std::invalid_argument("Unknown operation code");
        }
    }
};
