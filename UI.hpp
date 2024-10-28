#include<bits/stdc++.h>
#include<conio.h>
using namespace std;

class ANSI_UI {
    string bg_value = "#FFF";
    int tr = 0, tg = 0, tb = 0;
    int tbr = 255, tbg = 255, tbb = 255;
    int temptr = 0, temptg = 0, temptb = 0;
    int temptbr = 255, temptbg = 255, temptbb = 255;

    void set_temp_values_t(int r, int g, int b) {
        temptr = r;
        temptg = g;
        temptb = b;
    }

    void set_temp_values_tb(int r, int g, int b) {
        temptbr = r;
        temptbg = g;
        temptbb = b;
    }

public:

#define BGX_WHITE "#FFF"
#define BGX_BLACK "#000"
#define BGX_BLUE "#2244A6"
#define BGX_RED "#A62233"
#define BGX_GREEN "#276727"
    void bg_hex(string hex) {
        print("\033]11;{}\a", hex);
    }

    int get_terminal_width() {
        cout << "\033[250G";
        string response;
        getline(std::cin, response);
        return stoi(response.substr(4, response.find('R')));
    }

#define RGB_WHITE 255,255,255
#define RGB_BLACK 0,0,0
#define RGB_RED 166,34,51
    void txt_rgb(int r, int g, int b) {
        print("\e[38;2;{};{};{}m", r, g, b);
        set_temp_values_t(r, g, b);
    }
    void txtbg_rgb(int r, int g, int b) {
        print("\e[48;2;{};{};{}m", r, g, b);
        set_temp_values_tb(r, g, b);
    }

    template<typename ...args>
    void set_cvalues_default(args&& ...arg) {
        int arr[]{ arg... };
        int* carr[]{ &tr, &tg, &tb, &tbr, &tbg, &tbb };
        for (int i{}; i < 6; i++) {
            *carr[i] = arr[i];
        }
    }
    void set_cvalues_default() {
        int* carr[]{ &tr, &tg, &tb, &tbr, &tbg, &tbb };
        int tcarr[]{ temptr, temptg, temptb, temptbr, temptbg, temptbb };
        for (int i{}; i < 6; i++) {
            *carr[i] = tcarr[i];
        }
    }

#define C256_WHITE 255
#define C256_BLACK 0
    void txt_256(int color) {
        print("\e[38;5;{}m", color);
    }
    void txtbg_256(int color) {
        print("\e[48;5;{}m", color);
    }


    void clear() {
        print("\e[1J\e[1;1H");
    }
    void refresh_frame() {
        print("\e[3J\e[1;1H");
    }
    void clear_lines(int no = 0) {
        if (no == 0) {
            cout << "\e[A\e[2K\e[1G";
        }
        for (int i{}; i < no; i++) {
            print("\e[1F\e[2K\e[1G");
        }
    }
    void cursor_start() {
        print("\e[1;1H");
    }

    void reset_window() {
        bg_hex(bg_value);
        txt_rgb(tr, tg, tb);
        txtbg_rgb(tbr, tbg, tbb);
    }

    void reset_txt() {
        txt_rgb(tr, tg, tb);
        txtbg_rgb(tbr, tbg, tbb);
    }

    void pause() {
        cout << "\e[sPress Enter to Contiue...";
        pause_nt();
        cout << "\e[u\e[s" << string(31, ' ') << "\e[u";
    }
    void pause_nt() {
        while (!kbhit()) { this_thread::sleep_for(chrono::milliseconds(100)); }
        getch();
    }

    ANSI_UI() {
        bg_hex(BGX_WHITE);
        txt_rgb(RGB_BLACK);
        set_cvalues_default(RGB_BLACK, RGB_WHITE);
    }

#define LIGHT_THEME 0
#define DARK_THEME 1
#define RED_THEME 2
#define NILL_OBJ -1
    ANSI_UI(const int preset) {
        switch (preset)
        {
        case 1:
            bg_hex(BGX_BLACK);
            txt_rgb(RGB_WHITE);
            set_cvalues_default(RGB_WHITE, RGB_BLACK);
            break;
        case 2:
            bg_hex(BGX_BLACK);
            txt_rgb(200, 70, 70);
            set_cvalues_default(200, 70, 70, RGB_BLACK);
            break;
        default:
            bg_hex(BGX_WHITE);
            txt_rgb(RGB_BLACK);
            set_cvalues_default(RGB_BLACK, RGB_WHITE);
            break;
        }
    }
};