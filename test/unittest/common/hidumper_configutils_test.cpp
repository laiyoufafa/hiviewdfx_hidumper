/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
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
#include "hidumper_configutils_test.h"
using namespace std;
using namespace testing::ext;
using namespace OHOS;
using namespace OHOS::HiviewDFX;
namespace OHOS {
namespace HiviewDFX {
const int HidumperConfigUtilsTest::PID_EMPTY = -1;
const int HidumperConfigUtilsTest::UID_EMPTY = -1;
const int HidumperConfigUtilsTest::PID_TEST = 100;
const std::string HidumperConfigUtilsTest::DUMPER_NAME = "dumper_kernel_version";
void HidumperConfigUtilsTest::SetUpTestCase(void)
{
}

void HidumperConfigUtilsTest::TearDownTestCase(void)
{
}

void HidumperConfigUtilsTest::SetUp(void)
{
}

void HidumperConfigUtilsTest::TearDown(void)
{
}

/**
 * @tc.name: HidumperConfigUtils001
 * @tc.desc: Test GetDumper by index
 * @tc.type: FUNC
 */
HWTEST_F (HidumperConfigUtilsTest, HidumperConfigUtils001, TestSize.Level3)
{
    int index = -1;
    std::vector<std::shared_ptr<DumpCfg>> result;
    ConfigUtils configUtils(nullptr);
    auto args = OptionArgs::Create();
    args->SetPid(PID_EMPTY, UID_EMPTY);
    DumpStatus ret = configUtils.GetDumper(index, result, args);
    EXPECT_NE(ret, DumpStatus::DUMP_OK);

    index = 100000;
    result.clear();
    ret = configUtils.GetDumper(index, result, args);
    EXPECT_NE(ret, DumpStatus::DUMP_OK);

    index = 0;
    result.clear();
    ret = configUtils.GetDumper(index, result, args);
    EXPECT_EQ(ret, DumpStatus::DUMP_OK);

    ASSERT_TRUE(!result.empty());
    ASSERT_TRUE(!result[0]->name_.empty());
    ASSERT_TRUE(result[0]->target_.empty());
    ASSERT_TRUE(result[0]->args_ == args);
}

/**
 * @tc.name: HidumperConfigUtils002
 * @tc.desc: Test GetDumper by index.
 * @tc.type: FUNC
 */
HWTEST_F (HidumperConfigUtilsTest, HidumperConfigUtils002, TestSize.Level3)
{
    int index = 1;
    std::vector<std::shared_ptr<DumpCfg>> result;
    ConfigUtils configUtils(nullptr);
    auto args = OptionArgs::Create();
    args->SetPid(PID_EMPTY, UID_EMPTY);
    DumpStatus ret = configUtils.GetDumper(index, result, args);
    EXPECT_EQ(ret, DumpStatus::DUMP_OK);

    std::size_t allSum = result.size();
    index = 1;
    result.clear();
    ret = configUtils.GetDumper(index, result, args);
    EXPECT_EQ(ret, DumpStatus::DUMP_OK);
    std::size_t highSum = result.size();

    index = 1;
    result.clear();
    ret = configUtils.GetDumper(index, result, args);
    EXPECT_EQ(ret, DumpStatus::DUMP_OK);
    std::size_t middleSum = result.size();

    index = 1;
    result.clear();
    ret = configUtils.GetDumper(index, result, args);
    EXPECT_EQ(ret, DumpStatus::DUMP_OK);
    std::size_t lowSum = result.size();

    index = 1;
    result.clear();
    ret = configUtils.GetDumper(index, result, args);
    EXPECT_EQ(ret, DumpStatus::DUMP_OK);
    std::size_t noneSum = result.size();

    ASSERT_TRUE(highSum <= allSum);
    ASSERT_TRUE(middleSum <= allSum);
    ASSERT_TRUE(lowSum <= allSum);
    ASSERT_TRUE(noneSum <= allSum);
}

/**
 * @tc.name: HidumperConfigUtils003
 * @tc.desc: Test GetDumper by name.
 * @tc.type: FUNC
 */
HWTEST_F (HidumperConfigUtilsTest, HidumperConfigUtils003, TestSize.Level3)
{
    std::string name;
    std::vector<std::shared_ptr<DumpCfg>> result;
    ConfigUtils configUtils(nullptr);
    auto args = OptionArgs::Create();
    args->SetPid(PID_EMPTY, UID_EMPTY);
    DumpStatus ret = configUtils.GetDumper(name, result, args);
    EXPECT_NE(ret, DumpStatus::DUMP_OK);

    name = DUMPER_NAME;
    result.clear();
    ret = configUtils.GetDumper(name, result, args);
    EXPECT_EQ(ret, DumpStatus::DUMP_OK);

    ASSERT_TRUE(!result.empty());
    ASSERT_TRUE(result[0]->name_ == name);
}
} // namespace HiviewDFX
} // namespace OHOS