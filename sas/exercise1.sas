/*
1) Options are used in SAS to customize a step in order to better model or display the results the user wants.
2) FREQ
3) False
*/

PROC CONTENTS DATA  = sashelp.baseball ORDER = CASECOLLATE;
RUN;

PROC UNIVARIATE DATA  = sashelp.baseball CIBASIC (ALPHA = .1)
	VAR = salary;
RUN;

PROC FREQ DATA  = sashelp.baseball;
	TABLES = league * division / NOCOL;
RUN:

PROC SGPLOT DATA = sashelp.baseball;
	HISTOGRAM salary/fillattrs=(color=red);
	DENSITY salary/TYPE = KERNEL;
RUN;

PROC SGPLOT DATA = sashelp.baseball;
	SCATTER X=YrMajor Y=Salary;
	DATASKIN = MATTE;
RUN;