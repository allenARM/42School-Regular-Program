#include "header.h"
#include <stdio.h>
#include <wchar.h>
int main()
{
	// int c = 3;
	// int b = -3;
	// wchar_t wide[4] = {0x01A9};
	// wchar_t newstring[4] = {0x43, 0x01A9, 0x43, 0};
	ft_printf("Hello %c %lc %lc terter\n", 'h', 0x43, 0x01A9);
	printf("\n--reg_printf--\n");
	printf("\neh: %d\n", printf("%c %lc %lc", 'h', 0x43, 0x01A9));
	printf("\n--reg_printf--\n");


// 	#include <locale.h>
// int printed_characters;
// int str = 1;
// wchar_t *newstring = L"Another text 汉字 привет :woman-facepalming:";
//
// setlocale(LC_ALL, "");
// printed_characters = printf("%S\n", newstring);
// printf("wstring printed by printf: %d\n", printed_characters);
// printed_characters = ft_printf("%S\n", newstring);
// printf("wstring printed by printz: %d\n", printed_characters);
// printed_characters = printf("%p\n", &str);
// printf("chars printed by printf: %d\n", printed_characters);
// printed_characters = ft_printf("%p\n", &str);
// printf("chars printed by printz: %d\n", printed_characters);
	// ft_putstr("\n-------------\n");
	// wchar_t wide[4] = {0x01A9};
  //
	// int i = 0;
	// while(wide[i])
	// {
	// 	write(1, &wide[i], 1);
	// 	i++;
	// }
	// 	ft_putstr("\n-------------\n");
  //
	// printf("\n-----\n%lc\n------\n", 0x01A9);
	// printf("-----------\nHello %+10*.5d terter\n", 13);
	// printf("Hello %d terter\n", 13);
	// ft_printf("Hello %d terter\n", -11);
	// printf("Hello %d terter\n", -11);
  //
	// ft_printf("Hello %i terter\n", 10);
	// printf("Hello %i terter\n", 10);
	// ft_printf("Hello %i terter\n", -5);
	// printf("Hello %i terter\n", -5);
  //
	// ft_printf("Hello %s terter\n", "");
	// printf("Hello %s terter\n", "");
	// ft_printf("Hello %s terter\n", "world");
	// printf("Hello %s terter\n", "world");
  //
	// ft_printf("Hello %c terter\n", 'a');
	// printf("Hello %c terter\n", 'a');
	// ft_printf("Hello %c terter\n", 33);
	// printf("Hello %c terter\n", 33);
	// ft_printf("Hello %o terter\n", 1);
	// printf("Hello %o terter\n", 1);
	// ft_printf("Hello %o terter\n", 100);
	// printf("Hello %o terter\n", 100);
  //
	// ft_printf("Hello %u terter\n", 1);
	// printf("Hello %u terter\n", 1);
	// ft_printf("Hello %u terter\n", -1);
	// printf("Hello %u terter\n", -1);
  //
	// ft_printf("Hello %p terter\n", &c);
	// printf("Hello %p terter\n", &c);
	// ft_printf("Hello %p terter\n", &b);
	// printf("Hello %p terter\n", &b);
  //
	// ft_printf("Hello %x terter\n", 13);
	// printf("Hello %x terter\n", 13);
	// ft_printf("Hello %x terter\n", -3);
	// printf("Hello %x terter\n", -3);
  //
	// ft_printf("Hello % % terter\n");
	// printf("Hello % % terter\n");
  //
  //
	// printf("%d\n", ft_printf("Hello %x terter", 120));
	// printf("%d\n", printf("Hello %x terter", 120));
	// printf("%d\n", ft_printf("Hello %x terter", 12));
	// printf("%d\n", printf("Hello %x terter", 12));
	// printf("%d\n", ft_printf("Hello %p terter", &b));
	// printf("%d\n", printf("Hello %p terter", &b));
  //
	// printf("%d\n", ft_printf("Hello %x terter", 74));
	// printf("%d\n", printf("Hello %x terter", 74));
  //
	// ft_printf("Hello %x terter\n", NULL);
	// printf("Hello %p terter\n", NULL);
	// ft_printf("%s%s%s\n", "test", "test", "test");
	// ft_printf("%%%");
  //
	// ft_printf(" %s ", "HASFASFASD");
	// printf(" == %s \n", "HASFASFASD");
	// ft_printf("%d", 42);
	// printf(" == %d\n", 42);
	// ft_printf("%d%d", 42, 41);
	// printf(" == %d%d\n", 42, 41);
	// ft_printf("%d%d%d", 42, 43, 44);
	// printf(" == %d%d%d\n", 42, 43, 44);
	// ft_printf("%x", 505);
	// printf(" == %x\n", 505);
	// ft_printf("%p", &ft_printf);
	// printf(" == %p\n", &ft_printf);
	// ft_printf("%o", 40);
	// printf(" == %o\n", 40);
	// ft_printf("%x", 1000);
	// printf(" == %x\n", 1000);
	// ft_printf("%s", NULL);
	// printf(" == %s\n", NULL);
	// ft_printf("%s%s", "test", "test");
	// printf(" == %s%s\n", "test", "test");
	// ft_printf("%s%s%s", "test", "test", "test");
	// printf(" == %s%s%s\n", "test", "test", "test");
	// ft_printf("%s HALO %s", NULL, "KEK");
	// printf(" == %s HALO %s\n", NULL, "KEK");

	// ft_printf("Hello %d terter\n", counter);
	// printf("Hello %d terter\n", coimu);
	return 0;
}
