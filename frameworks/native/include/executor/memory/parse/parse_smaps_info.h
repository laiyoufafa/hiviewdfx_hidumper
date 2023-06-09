/*
 * Copyright (C) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef PARSE_SMAPS_INFO_H
#define PARSE_SMAPS_INFO_H
#include <string>
#include <vector>
#include "executor/memory/memory_filter.h"
namespace OHOS {
namespace HiviewDFX {
class ParseSmapsInfo {
public:
    ParseSmapsInfo();
    ~ParseSmapsInfo();

    using PairMatrix = std::vector<std::pair<std::string, uint64_t>>;
    using PairMatrixGroup = std::vector<std::pair<std::string, PairMatrix>>;

    bool GetInfo(const MemoryFilter::MemoryType &memType, const int &pid, PairMatrixGroup &result);

private:
    std::string memGroup_ = "";

    bool ParseSmaps(const MemoryFilter::MemoryType &memType, int &pid, PairMatrixGroup &result);
    bool GetValue(const MemoryFilter::MemoryType &memType, const std::string &str, std::string &type, uint64_t &value);
    void ClacByGroup(const PairMatrixGroup &infos, PairMatrixGroup &result);

    void CalcGroup(const std::string &group, const std::string &type, const uint64_t &value, PairMatrixGroup &infos);
    void InsertGroup(const std::string &group, const std::string &type, const uint64_t &value, PairMatrixGroup &infos);
    void InsertType(const std::string &group, const std::string &type, const uint64_t &value, PairMatrixGroup &infos);
    bool GetHasPidValue(const std::string &str, std::string &type, uint64_t &value);
    bool GetNoPidValue(const std::string &str, std::string &type, uint64_t &value);

    PairMatrixGroup DataSort(const PairMatrixGroup &infos, const std::vector<std::string> &tags);
};
} // namespace HiviewDFX
} // namespace OHOS
#endif
