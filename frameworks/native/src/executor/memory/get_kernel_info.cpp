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

#include "executor/memory/get_kernel_info.h"
#include <memory>
#include "executor/memory/parse/parse_vmallocinfo.h"
#include "executor/memory/memory_filter.h"
#include "executor/memory/memory_util.h"
using namespace std;
namespace OHOS {
namespace HiviewDFX {
GetKernelInfo::GetKernelInfo()
{
}
GetKernelInfo::~GetKernelInfo()
{
}

/**
 * @description: Get the usage of kernel
 * @param {PairMatrix} &infos-the meminfo
 * @param {uint64_t} &value-the usage of kernel
 * @return {bool} - true:success,false-fail
 */
bool GetKernelInfo::GetKernel(const PairMatrix &infos, uint64_t &totalValue)
{
    for (auto info : infos) {
        string key = info.first;
        for (auto str : MemoryFilter::GetInstance().CALC_KERNEL_TOTAL_) {
            bool sub = MemoryUtil::GetInstance().GetKey(str);
            if (key == str) {
                uint64_t value = info.second;
                if (sub) {
                    totalValue -= value;
                } else {
                    totalValue += value;
                }
            }
        }
    }

    uint64_t vmallocValue = 0;
    unique_ptr<ParseVmallocinfo> parseVmallocinfo = make_unique<ParseVmallocinfo>();
    bool success = parseVmallocinfo->GetVmallocinfo(vmallocValue);
    if (success) {
        totalValue += vmallocValue / MemoryUtil::GetInstance().BYTE_TO_KB_;
    }

    return success;
}
} // namespace HiviewDFX
} // namespace OHOS
