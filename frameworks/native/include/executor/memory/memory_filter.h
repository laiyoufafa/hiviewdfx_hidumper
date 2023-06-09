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

#ifndef MEMORY_FILTER_H
#define MEMORY_FILTER_H
#include <string>
#include <vector>
#include "singleton.h"
#include "util/string_utils.h"

namespace OHOS {
namespace HiviewDFX {
class MemoryFilter : public Singleton<MemoryFilter> {
public:
    MemoryFilter();
    ~MemoryFilter();
    MemoryFilter(MemoryFilter const &) = delete;
    void operator=(MemoryFilter const &) = delete;

    enum MemoryType {
        APPOINT_PID,
        NOT_SPECIFIED_PID,
    };

    struct MemGroup {
        const std::string &group_;
        const std::string &matchRule_;
        const std::vector<std::string> &matchFile_;
    };

    const static MemGroup memGroups_[];

    int SMAPS_THREAD_NUM_ = 5;
    int HARDWARE_USAGE_THREAD_NUM_ = 5;

    const std::vector<std::string> TITLE_HAS_PID_ = {"Pss_Total",     "Shared_Clean", "Shared_Dirty", "Private_Clean",
                                                     "Private_Dirty", "Swap_Total",   "SwapPss_Total"};

    const std::vector<std::string> TITLE_NO_PID_ = {"Pss", "SwapPss"};

    std::vector<std::string> MEMINFO_TAG_ = {
        "MemTotal", "MemFree",       "Cached",       "SwapTotal", "KernelStack", "SUnreclaim", "PageTables",
        "Shmem",    "IonTotalCache", "IonTotalUsed", "Buffers",   "Mapped",      "Slab",       "VmallocUsed",
    };

    // The fields used to calculate kernel data
    std::vector<std::string> CALC_KERNEL_TOTAL_ = {"KernelStack", "SUnreclaim", "PageTables", "Shmem"};

    std::vector<std::string> CALC_PSS_TOTAL_ = {"Pss", "SwapPss"};
    std::vector<std::string> CALC_PROCESS_TOTAL_ = {"Pss", "SwapPss"};
    std::vector<std::string> CALC_TOTAL_PSS_ = {"Pss"};
    std::vector<std::string> CALC_TOTAL_SWAP_PSS_ = {"SwapPss"};
    std::vector<std::string> CALC_KERNEL_USED_ = {"Shmem", "Slab", "VmallocUsed", "PageTables", "KernelStack"};
    std::vector<std::string> CALC_FREE_ = {"MemFree"};
    std::vector<std::string> CALC_CACHED_ = {"Buffers", "Cached", "-Mapped"};
    std::vector<std::string> CALC_TOTAL_ = {"MemTotal"};
    std::vector<std::string> CALC_ZARM_TOTAL_;
    std::vector<std::string> HAS_PID_ORDER_ = {"Pss",           "Shared_Clean", "Shared_Dirty", "Private_Clean",
                                               "Private_Dirty", "Swap",         "SwapPss"};
    std::vector<std::string> NO_PID_ORDER_ = {"Pss"};
    bool ParseMemoryGroup(const std::string &content, const std::string &name, std::string &group);

private:
};
} // namespace HiviewDFX
} // namespace OHOS
#endif
