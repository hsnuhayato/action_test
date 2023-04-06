#!/usr/bin/env python3

import argparse
import datetime
from web_util import Webot

ID = ''
PASSWORD = ''
URL = ''

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('start_time', help='start time')
    parser.add_argument('--headless', action='store_true')
    args = parser.parse_args()

    webot = Webot(URL, args.headless)
    webot.driver.find_element_by_name('uid').send_keys(ID)
    webot.driver.find_element_by_name('psw').send_keys(PASSWORD)
    webot.driver.find_element_by_xpath('//input[@type="submit"]').click()
    webot.wait_id('PA001&007', 10)
    webot.driver.find_element_by_id('PA001&007').click()
    webot.driver.find_element_by_xpath(
        "//li[@onclick=\"openUrl('./?_GLOC=PA1NPA.PA0101.G01', 'PA001',"
        " 'MAIN_MENU','0', '0', '222222  ','PA001','1'); return false;\"]").click()
    webot.driver.switch_to.window(webot.driver.window_handles[1])

    for i, regist_btn in enumerate(webot.driver.find_elements_by_id('registBtn')):
        # if not start_time_entry.is_displayed()
        # or start_time_entry.get_attribute('data-face-validate-value'):
        if not regist_btn.is_displayed():
            continue
        print(f'day index {i}')
        start_time_entry = webot.driver.find_elements_by_xpath(
            '//input[@data-face-validate="始業時刻"]')[i]
        end_time_entry = webot.driver.find_elements_by_xpath(
            '//input[@data-face-validate="終業時刻"]')[i]
        end_time = datetime.datetime.now().strftime('%H:%M')

        # input time
        start_time_entry.clear()
        end_time_entry.clear()
        start_time_entry.send_keys(args.start_time)
        end_time_entry.send_keys(end_time)

        # submit
        regist_btn.click()
        webot.wait_hidden(regist_btn, 3)
        webot.try_cmd(3)
        webot.try_cmd(4)
        break

    webot.tear_down()
