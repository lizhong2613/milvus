// Copyright (C) 2019-2020 Zilliz. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance
// with the License. You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software distributed under the License
// is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
// or implied. See the License for the specific language governing permissions and limitations under the License.

#pragma once

#include "server/delivery/strategy/ReqStrategy.h"
#include "utils/Status.h"
#include "value/config/ConfigMgr.h"

#include <memory>
#include <queue>
#include <string>

namespace milvus {
namespace server {

class SearchReqStrategy : public ReqStrategy, public ConfigObserver {
 public:
    SearchReqStrategy();

    ~SearchReqStrategy();

    Status
    ReScheduleQueue(const BaseReqPtr& request, std::queue<BaseReqPtr>& queue) override;

 public:
    void
    ConfigUpdate(const std::string& name) override;

 private:
    int64_t search_combine_nq_ = 0;
};

using ReqStrategyPtr = std::shared_ptr<ReqStrategy>;
}  // namespace server
}  // namespace milvus
