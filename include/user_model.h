/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef INCLUDE_USER_MODEL_H_
#define INCLUDE_USER_MODEL_H_

#include <string>
#include "user_profile.h"
#include "notification_event_type.h"
#include "../src/naive_bayes.h"

namespace usermodel {

class UserModelDelegate {
  void PageNavigated(const std::string& html, const std::string& url, uint32_t window_id, uint32_t tab_id);
};

class UserModel {
 public:
    bool initializePageClassifier(const std::string& model);
    void onPageLoad(const std::string& html, const std::string& url, uint32_t window_id, uint32_t tab_id);
    // void onTabFocus(uint32_t window_id, uint32_t tab_id);
    // void onNotificationEvent(NotificationEventType type);
    // void updateState();
    std::vector<double>  classifyPage(const std::string& data);
    static std::string winningCategory(const std::vector<double>& scores, const std::vector<std::string>& taxonomies);
    NaiveBayes page_classifier;
    bool IsInitialized();

 private:
    // UserProfile user_profile;
    // bool isSearchURL(const std::string& url);
    // bool isShoppingIntent(const std::string& url, const std::string& html);
    bool initialized_ = false;
};
}  // namespace usermodel

#endif  // INCLUDE_USER_MODEL_H_
