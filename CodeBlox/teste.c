#include <stdio.h>
#include <string.h>

void print_in_columns(const char *column1, const char *column2, const char *column3, int column4) {
    int column1_width = 20;
    int column2_width = 20;
    int column3_width = 20;
    int column4_width = 20;

    int column1_padding = (column1_width - strlen(column1)) / 2;
    int column2_padding = (column2_width - strlen(column2)) / 2;
    int column3_padding = (column3_width - strlen(column3)) / 2;
    int column4_padding = (column4_width - column4) / 2;

    printf("%*s%s%*s %*s%s%*s %*s%s%*s %*s%d%*s\n",
           column1_padding, "", column1, column1_padding, "",
           column2_padding, "", column2, column2_padding, "",
           column3_padding, "", column3, column3_padding, "",
           column4_padding, "", column4, column4_padding, "");
}

int main() {
    // Exemplo de uso
    print_in_columns("Running task =", "[T1]", "[4]", 32, "for", 0, "units.");

    return 0;
}
