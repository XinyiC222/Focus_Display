<h1>Focus Display</h1>
A personal device that is powered by a ESP32 with an E-ink display. It shows the weather, date, and you can also set a timer with the rotary encoder on the side for control!
<h1>Why I built it</h1>
I built this becuase as a student, it really helps me when I had a timer set for each task, espcially using the pomodoro method. This not only makes me feel organized, but I also get this done quicker. I was inspired by projects online that I saw. One of the projects I used as inspo was the E-ink Pomodoro timer by Cameron Coward:https://www.hackster.io/news/increase-your-productivity-with-this-diy-e-ink-pomodoro-timer-986085d57d91. Having a timer on my table would be way better and less distraction then setting up a timer on my phone.
<h1>Process</h1>
I first looked up some components I could use on aliexpress, then I started 3d modeling the case in Fusion360 based on the components!

<img width="1504" height="934" alt="image" src="https://github.com/user-attachments/assets/fc4b2041-4878-4b54-b2ea-6a07ff7fc6d8" />
 After the inital design, I thought about other ways to improve it. at first, there was only the e-ink screen and the rotary encoder. Then I decided to add the buzzer and some rubber feets to prevent the device from slipping. The case would be 3d printed. I also added a few hole on the back of the case so that the buzzer's noise can be heard from the back. After I finished desigining I started programming it! I'm almost done with the code as of now.

<h1>How to make your own!</h1>
Here below is a wiring diagram that show how each part connects! You can use this as a guide. 
<img width="856" height="530" alt="Screenshot 2026-07-11 at 2 45 04 PM" src="https://github.com/user-attachments/assets/18ea8236-b767-446c-912e-bf5077aaf3f2" />
The 3d printed case is under the 3d Print Files Folder. If you'll like to check out the project files you can find it in the folder called Project Files. The code files are all under src.

<h1>Flash</h1>
First plug in your esp32 to your device. Then install the platformio extension in VScode. Then install the ESP32 driver into the device. Mines uses CH340, so I got mines from here:(https://www.wch-ic.com/downloads/CH341SER_ZIP.html) Using the source files you got in this repository, you can easily flash it into your ESP32 by clicking the arrow button on the bottom of vscode.



## BOM
| Item  |  Purpose | Price | Source |
| ------------- | ------------- | ------------- | ------------- |
| Mini BreadBoard | multiple GND and 3v3 | $2.16 | [Aliexpress](https://www.aliexpress.us/item/3256805668858915.html?mp=1&pdp_npi=6@dis!USD!USD+2.14!USD+0.99!!USD+0.99!!!@21030f8317838070782482543e0ff1!12000034586923065!ct!US!7294405090!!1!0!&gatewayAdapt=glo2usa) |
| Rubber Pads | Prevent slipping | $2.33 | [Aliexpress](https://www.aliexpress.us/item/3256806771014461.html?mp=1&pdp_npi=6@dis!USD!USD+2.35!USD+2.35!!USD+2.35!!!@21030f8317838073132111949e0ff1!12000039096298475!ct!US!7294405090!!1!0!&gatewayAdapt=glo2usa) |
| ESP 32 USB-C | Powerhouse | $6.65 | [Aliexpress](https://www.aliexpress.us/item/3256812280051548.html?spm=a2g0o.productlist.main.4.39d0512bSwKJnf&aem_p4p_detail=202608070024079666624382305660000080180&algo_pvid=c37651cc-fe4b-44b0-aa0f-9f1bddbbcd6b&algo_exp_id=c37651cc-fe4b-44b0-aa0f-9f1bddbbcd6b-3&pdp_ext_f=%7B%22order%22%3A%22137%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21USD%215.52%210.99%21%21%2137.02%216.62%21%402101e5ab17860874477068118e0c81%2112000058730764436%21sea%21US%218014119481%21ABX%211%210%21n_tag%3A-29910%3Bd%3Ab9f63e53%3Bm03_new_user%3A-29895%3BpisId%3A5000000210798120&curPageLogUid=irZ0Xq26cFBo&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005012466366300%7C_p_origin_prod%3A&search_p4p_id=202608070024079666624382305660000080180_1) |
| Passive Buzzer | To alert when timer starts/stops | $3.75 | [Aliexpress](https://www.aliexpress.us/item/3256806852143766.html?mp=1&sourceType=570&pdp_npi=6@dis!USD!USD+3.18!USD+1.59!!USD+1.22!!!@21030f8317838074912838475e0ff1!12000039180355191!ct!US!7294405090!!1!0!&pdp_ext_f=%7B%22cart2PdpParams%22:%7B%22sourceType%22:%22570%22,%22cartSource%22:%22main%22%7D%7D&gatewayAdapt=glo2usa) |
| KY-040 Rotary Encoder | To change the timer and for control | $1.89 | [Aliexpress](https://www.aliexpress.us/item/3256809392189426.html?mp=1&sourceType=570&pdp_npi=6@dis!USD!USD+3.95!USD+1.79!!USD+1.38!!!@21030f8317838074912838475e0ff1!12000049518740990!ct!US!7294405090!!1!0!&pdp_ext_f=%7B%22cart2PdpParams%22:%7B%22sourceType%22:%22570%22,%22cartSource%22:%22main%22%7D%7D&gatewayAdapt=glo2usa) |
| WeAct 3.7 Inch Epaper Module E-paper | Display | $11.20 | [Aliexpress](https://www.aliexpress.us/item/3256809525844585.html?mp=1&pdp_npi=6@dis!USD!USD+11.66!USD+11.66!!USD+11.66!!!@21030f8317838073132111949e0ff1!12000049927000015!ct!US!7294405090!!1!0!&gatewayAdapt=glo2usa) |
| Jumper Wires | connecting | $0.99 | [Aliexpress](https://www.aliexpress.us/item/3256806860151128.html?mp=1&pdp_npi=6@dis!USD!USD+4.63!USD+2.69!!USD+2.69!!!@21030f8317838073132111949e0ff1!12000039211508993!ct!US!7294405090!!1!0!&gatewayAdapt=glo2usa) |
| 3d printed case | case | $0 | Printing Legion(Hack Club) |
|  |  |  | **Subtotal: $27.84**  |
|  |  | Aliexpress: $27.84 |  **Total (tax + shipping): $33.59** |

