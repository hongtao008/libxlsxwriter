/*****************************************************************************
 * Test cases for libxlsxwriter.
 *
 * Test to compare output against Excel files.
 *
 * Copyright 2014-2021, John McNamara, jmcnamara@cpan.org
 *
 */

#include "xlsxwriter.h"

int main() {

    lxw_workbook  *workbook  = workbook_new("test_hyperlink14.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    lxw_format *format = workbook_add_format(workbook);

    format_set_align(format, LXW_ALIGN_CENTER);

    worksheet_write_string(worksheet, CELL("A1"), "Perl Home", NULL);

    worksheet_merge_range(worksheet, RANGE("C4:E5"), "http://www.perl.org/", format);
    worksheet_write_url_opt(worksheet, CELL("C4"), "http://www.perl.org/", format, "Perl Home", NULL);


    return workbook_close(workbook);
}
