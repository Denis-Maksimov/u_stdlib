

#include "slre.h"
#include <u_stdlib.h>
#include <stdio.h>

const char* request = 
"GET /index.html HTTP/1.0\r\n"
"Host: queuev4.vk.com\r\n"
"User-Agent: Mozilla/5.0 (X11; Linux x86_64; rv:68.0) Gecko/20100101 Firefox/68.0\r\n"
"Accept: */*\r\n"
"Accept-Language: ru-RU,ru;q=0.8,en-US;q=0.5,en;q=0.3\r\n"
"Accept-Encoding: gzip, deflate, br\r\n"
"Content-Type: application/x-www-form-urlencoded\r\n"
"X-Requested-With: XMLHttpRequest\r\n"
"Content-Length: 189\r\n"
"DNT: 1\r\n"
"Connection: keep-alive\r\n"
"Referer: https://queuev4.vk.com/q_frame.php?7\r\n"
"Cookie: remixlang=3; remixstid=115918593_Lg9b0frclspylOBzEzNZe7kepZ0fN5bATpCz4Qju0Zc; remixrefkey=a6437af13ae5308d74; remixflash=0.0.0; remixscreen_depth=24; remixdt=0; remixsid=65121621b587f352abe5bb0a9ee1c97ad85dcb456419abbf8f1406afb1056; remixusid=M2UwZTliY2E0YzhiMTU2YjY1ZmU4Zjkz; remixseenads=0; tmr_reqNum=634; tmr_lvid=752d92037b35dbbaaf8d51ee43e2a719; tmr_lvidTS=1574628452923; remixua=153%7C-1%7C277%7C1668767195; remixscreen_orient=1; remixscreen_width=1920; remixscreen_height=1080; remixscreen_dpr=1; remixscreen_winzoom=1; remixgp=2a195ddec1cf9005b144f2f19cb855e3\r\n"
"TE: Trailers;\r\n"
"\r\n";



const char* regex[] = {
    "^\\s*(\\S+)" //method
    "\\s+(\\S+)"  //uri
    "\\s+HTTP/(\\d\\.\\d)", //verse
    // ".+?[Hh]ost\\s*?:(\\S+)",
    "(Connection)\\s*:\\s*(\\S+)",
    "(Accept)\\s*:\\s*(\\S+)",
    "(Cookie)\\s*:\\s*(\\S+)"

};


int main() {

        
    


    struct slre_cap caps[15];
    int ercode=0;
    if ((ercode=slre_match(regex[0], request, u_strlen(request), caps, 3, 0)) > 0) 
    {
        printf( "Method: [%.*s],\n"
                "URI: [%.*s],\n"
                "Verse: [%.*s]\n",
            caps[0].len, caps[0].ptr,
            caps[1].len, caps[1].ptr,
            caps[2].len, caps[2].ptr
            // caps[3].len, caps[3].ptr
            );
    } else {
        printf("Error parsing [%d]\n", ercode);
    }
    for(int i=1;i<4;i++){
    if ((ercode=slre_match(regex[i], request, u_strlen(request), caps, 2, 0)) > 0) 
    {
        printf( "%.*s: [%.*s],\n",
            caps[0].len, caps[0].ptr,
            caps[1].len, caps[1].ptr
            );
    } else {
        printf("Error parsing [%d]\n", ercode);
    }
    }


    return 0;
}

