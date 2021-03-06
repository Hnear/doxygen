"\\NeedsTeXFormat{LaTeX2e}\n"
"\\ProvidesPackage{doxygen}\n"
"\n"
"% Packages used by this style file\n"
"\\RequirePackage{alltt}\n"
"\\RequirePackage{array}\n"
"\\RequirePackage{calc}\n"
"\\RequirePackage{float}\n"
"\\RequirePackage{ifthen}\n"
"\\RequirePackage{verbatim}\n"
"\\RequirePackage[table]{xcolor}\n"
"\\RequirePackage{xtab}\n"
"\n"
"%---------- Internal commands used in this style file ----------------\n"
"\n"
"\\newcommand{\\ensurespace}[1]{%\n"
"  \\begingroup%\n"
"    \\setlength{\\dimen@}{#1}%\n"
"    \\vskip\\z@\\@plus\\dimen@%\n"
"    \\penalty -100\\vskip\\z@\\@plus -\\dimen@%\n"
"    \\vskip\\dimen@%\n"
"    \\penalty 9999%\n"
"    \\vskip -\\dimen@%\n"
"    \\vskip\\z@skip% hide the previous |\\vskip| from |\\addvspace|\n"
"  \\endgroup%\n"
"}\n"
"\n"
"\\newcommand{\\DoxyLabelFont}{}\n"
"\\newcommand{\\entrylabel}[1]{%\n"
"  {%\n"
"    \\parbox[b]{\\labelwidth-4pt}{%\n"
"      \\makebox[0pt][l]{\\DoxyLabelFont#1}%\n"
"      \\vspace{1.5\\baselineskip}%\n"
"    }%\n"
"  }%\n"
"}\n"
"\n"
"\\newenvironment{DoxyDesc}[1]{%\n"
"  \\ensurespace{4\\baselineskip}%\n"
"  \\begin{list}{}{%\n"
"    \\settowidth{\\labelwidth}{20pt}%\n"
"    \\setlength{\\parsep}{0pt}%\n"
"    \\setlength{\\itemsep}{0pt}%\n"
"    \\setlength{\\leftmargin}{\\labelwidth+\\labelsep}%\n"
"    \\renewcommand{\\makelabel}{\\entrylabel}%\n"
"  }%\n"
"  \\item[#1]%\n"
"}{%\n"
"  \\end{list}%\n"
"}\n"
"\n"
"\\newsavebox{\\xrefbox}\n"
"\\newlength{\\xreflength}\n"
"\\newcommand{\\xreflabel}[1]{%\n"
"  \\sbox{\\xrefbox}{#1}%\n"
"  \\setlength{\\xreflength}{\\wd\\xrefbox}%\n"
"  \\ifthenelse{\\xreflength>\\labelwidth}{%\n"
"    \\begin{minipage}{\\textwidth}%\n"
"      \\setlength{\\parindent}{0pt}%\n"
"      \\hangindent=15pt\\bfseries #1\\vspace{1.2\\itemsep}%\n"
"    \\end{minipage}%\n"
"  }{%\n"
"   \\parbox[b]{\\labelwidth}{\\makebox[0pt][l]{\\textbf{#1}}}%\n"
"  }%\n"
"}\n"
"\n"
"%---------- Commands used by doxygen LaTeX output generator ----------\n"
"\n"
"% Used by <pre> ... </pre>\n"
"\\newenvironment{DoxyPre}{%\n"
"  \\small%\n"
"  \\begin{alltt}%\n"
"}{%\n"
"  \\end{alltt}%\n"
"  \\normalsize%\n"
"}\n"
"\n"
"% Used by @code ... @endcode\n"
"\\newenvironment{DoxyCode}{%\n"
"  \\par%\n"
"  \\scriptsize%\n"
"  \\begin{alltt}%\n"
"}{%\n"
"  \\end{alltt}%\n"
"  \\normalsize%\n"
"}\n"
"\n"
"% Used by @example, @include, @includelineno and @dontinclude\n"
"\\newenvironment{DoxyCodeInclude}{%\n"
"  \\DoxyCode%\n"
"}{%\n"
"  \\endDoxyCode%\n"
"}\n"
"\n"
"% Used by @verbatim ... @endverbatim\n"
"\\newenvironment{DoxyVerb}{%\n"
"  \\footnotesize%\n"
"  \\verbatim%\n"
"}{%\n"
"  \\endverbatim%\n"
"  \\normalsize%\n"
"}\n"
"\n"
"% Used by @verbinclude\n"
"\\newenvironment{DoxyVerbInclude}{%\n"
"  \\DoxyVerb%\n"
"}{%\n"
"  \\endDoxyVerb%\n"
"}\n"
"\n"
"% Used by numbered lists (using '-#' or <ol> ... </ol>)\n"
"\\newenvironment{DoxyEnumerate}{%\n"
"  \\enumerate%\n"
"}{%\n"
"  \\endenumerate%\n"
"}\n"
"\n"
"% Used by bullet lists (using '-', @li, @arg, or <ul> ... </ul>)\n"
"\\newenvironment{DoxyItemize}{%\n"
"  \\itemize%\n"
"}{%\n"
"  \\enditemize%\n"
"}\n"
"\n"
"% Used by description lists (using <dl> ... </dl>)\n"
"\\newenvironment{DoxyDescription}{%\n"
"  \\description%\n"
"}{%\n"
"  \\enddescription%\n"
"}\n"
"\n"
"% Used by @image, @dotfile, @dot ... @enddot, and @msc ... @endmsc\n"
"% (only if caption is specified)\n"
"\\newenvironment{DoxyImage}{%\n"
"  \\begin{figure}[H]%\n"
"    \\begin{center}%\n"
"}{%\n"
"    \\end{center}%\n"
"  \\end{figure}%\n"
"}\n"
"\n"
"% Used by @image, @dotfile, @dot ... @enddot, and @msc ... @endmsc\n"
"% (only if no caption is specified)\n"
"\\newenvironment{DoxyImageNoCaption}{%\n"
"}{%\n"
"}\n"
"\n"
"% Used by @attention\n"
"\\newenvironment{DoxyAttention}[1]{%\n"
"  \\begin{DoxyDesc}{#1}%\n"
"}{%\n"
"  \\end{DoxyDesc}%\n"
"}\n"
"\n"
"% Used by @author and @authors\n"
"\\newenvironment{DoxyAuthor}[1]{%\n"
"  \\begin{DoxyDesc}{#1}%\n"
"}{%\n"
"  \\end{DoxyDesc}%\n"
"}\n"
"\n"
"% Used by @date\n"
"\\newenvironment{DoxyDate}[1]{%\n"
"  \\begin{DoxyDesc}{#1}%\n"
"}{%\n"
"  \\end{DoxyDesc}%\n"
"}\n"
"\n"
"% Used by @invariant\n"
"\\newenvironment{DoxyInvariant}[1]{%\n"
"  \\begin{DoxyDesc}{#1}%\n"
"}{%\n"
"  \\end{DoxyDesc}%\n"
"}\n"
"\n"
"% Used by @note\n"
"\\newenvironment{DoxyNote}[1]{%\n"
"  \\begin{DoxyDesc}{#1}%\n"
"}{%\n"
"  \\end{DoxyDesc}%\n"
"}\n"
"\n"
"% Used by @post\n"
"\\newenvironment{DoxyPostcond}[1]{%\n"
"  \\begin{DoxyDesc}{#1}%\n"
"}{%\n"
"  \\end{DoxyDesc}%\n"
"}\n"
"\n"
"% Used by @pre\n"
"\\newenvironment{DoxyPrecond}[1]{%\n"
"  \\begin{DoxyDesc}{#1}%\n"
"}{%\n"
"  \\end{DoxyDesc}%\n"
"}\n"
"\n"
"% Used by @copyright\n"
"\\newenvironment{DoxyCopyright}[1]{%\n"
"  \\begin{DoxyDesc}{#1}%\n"
"}{%\n"
"  \\end{DoxyDesc}%\n"
"}\n"
"\n"
"% Used by @remark\n"
"\\newenvironment{DoxyRemark}[1]{%\n"
"  \\begin{DoxyDesc}{#1}%\n"
"}{%\n"
"  \\end{DoxyDesc}%\n"
"}\n"
"\n"
"% Used by @return and @returns\n"
"\\newenvironment{DoxyReturn}[1]{%\n"
"  \\begin{DoxyDesc}{#1}%\n"
"}{%\n"
"  \\end{DoxyDesc}%\n"
"}\n"
"\n"
"% Used by @since\n"
"\\newenvironment{DoxySince}[1]{%\n"
"  \\begin{DoxyDesc}{#1}%\n"
"}{%\n"
"  \\end{DoxyDesc}%\n"
"}\n"
"\n"
"% Used by @see\n"
"\\newenvironment{DoxySeeAlso}[1]{%\n"
"  \\begin{DoxyDesc}{#1}%\n"
"}{%\n"
"  \\end{DoxyDesc}%\n"
"}\n"
"\n"
"% Used by @version\n"
"\\newenvironment{DoxyVersion}[1]{%\n"
"  \\begin{DoxyDesc}{#1}%\n"
"}{%\n"
"  \\end{DoxyDesc}%\n"
"}\n"
"\n"
"% Used by @warning\n"
"\\newenvironment{DoxyWarning}[1]{%\n"
"  \\begin{DoxyDesc}{#1}%\n"
"}{%\n"
"  \\end{DoxyDesc}%\n"
"}\n"
"\n"
"% Used by @internal\n"
"\\newenvironment{DoxyInternal}[1]{%\n"
"  \\paragraph*{#1}%\n"
"}{%\n"
"}\n"
"\n"
"% Used by @par and @paragraph\n"
"\\newenvironment{DoxyParagraph}[1]{%\n"
"  \\begin{list}{}{%\n"
"    \\settowidth{\\labelwidth}{40pt}%\n"
"    \\setlength{\\leftmargin}{\\labelwidth}%\n"
"    \\setlength{\\parsep}{0pt}%\n"
"    \\setlength{\\itemsep}{-4pt}%\n"
"    \\renewcommand{\\makelabel}{\\entrylabel}%\n"
"  }%\n"
"  \\item[#1]%\n"
"}{%\n"
"  \\end{list}%\n"
"}\n"
"\n"
"% Used by parameter lists\n"
"\\newenvironment{DoxyParams}[2][]{%\n"
"    \\par%\n"
"    \\tabletail{\\hline}%\n"
"    \\tablelasttail{\\hline}%\n"
"    \\tablefirsthead{}%\n"
"    \\tablehead{}%\n"
"    \\ifthenelse{\\equal{#1}{}}%\n"
"    {\\tablefirsthead{\\multicolumn{2}{l}{\\hspace{-6pt}\\bfseries\\fontseries{bc}\\selectfont\\color{darkgray} #2}\\\\[1ex]}%\n"
"     \\begin{xtabular}{|>{\\raggedleft\\hspace{0pt}}p{0.15\\textwidth}|%\n"
"                        p{0.805\\textwidth}|}}%\n"
"    {\\ifthenelse{\\equal{#1}{1}}%\n"
"      {\\tablefirsthead{\\multicolumn{2}{l}{\\hspace{-6pt}\\bfseries\\fontseries{bc}\\selectfont\\color{darkgray} #2}\\\\[1ex]}%\n"
"       \\begin{xtabular}{|>{\\centering}p{0.10\\textwidth}|%\n"
"                         >{\\raggedleft\\hspace{0pt}}p{0.15\\textwidth}|%\n"
"                         p{0.678\\textwidth}|}}%\n"
"      {\\tablefirsthead{\\multicolumn{2}{l}{\\hspace{-6pt}\\bfseries\\fontseries{bc}\\selectfont\\color{darkgray} #2}\\\\[1ex]}%\n"
"       \\begin{xtabular}{|>{\\centering}p{0.10\\textwidth}|%\n"
"                         >{\\centering\\hspace{0pt}}p{0.15\\textwidth}|%\n"
"                         >{\\raggedleft\\hspace{0pt}}p{0.15\\textwidth}|%\n"
"                         p{0.501\\textwidth}|}}%\n"
"    }\\hline%\n"
"}{%\n"
"    \\end{xtabular}%\n"
"    \\tablefirsthead{}%\n"
"    \\vspace{6pt}%\n"
"}\n"
"\n"
"% Used for fields of simple structs\n"
"\\newenvironment{DoxyFields}[1]{%\n"
"    \\par%\n"
"    \\tabletail{\\hline}%\n"
"    \\tablelasttail{\\hline}%\n"
"    \\tablehead{}%\n"
"    \\tablefirsthead{\\multicolumn{2}{l}{\\hspace{-6pt}\\bfseries\\fontseries{bc}\\selectfont\\color{darkgray} #1}\\\\[1ex]}%\n"
"    \\begin{xtabular}{|>{\\raggedleft\\hspace{0pt}}p{0.15\\textwidth}|%\n"
"                         p{0.15\\textwidth}|%\n"
"                         p{0.63\\textwidth}|}%\n"
"    \\hline%\n"
"}{%\n"
"    \\end{xtabular}%\n"
"    \\tablefirsthead{}%\n"
"    \\vspace{6pt}%\n"
"}\n"
"\n"
"% Used for parameters within a detailed function description\n"
"\\newenvironment{DoxyParamCaption}{%\n"
"  \\renewcommand{\\item}[2][]{##1 {\\em ##2}}%\n"
"}{%\n"
"}\n"
"\n"
"% Used by return value lists\n"
"\\newenvironment{DoxyRetVals}[1]{%\n"
"    \\par%\n"
"    \\tabletail{\\hline}%\n"
"    \\tablelasttail{\\hline}%\n"
"    \\tablehead{}%\n"
"    \\tablefirsthead{\\multicolumn{2}{l}{\\hspace{-6pt}\\bfseries\\fontseries{bc}\\selectfont\\color{darkgray} #1}\\\\[1ex]}%\n"
"    \\begin{xtabular}{|>{\\raggedleft\\hspace{0pt}}p{0.25\\textwidth}|%\n"
"                          p{0.705\\textwidth}|}%\n"
"    \\hline%\n"
"}{%\n"
"    \\end{xtabular}%\n"
"    \\tablefirsthead{}%\n"
"    \\vspace{6pt}%\n"
"}\n"
"\n"
"% Used by exception lists\n"
"\\newenvironment{DoxyExceptions}[1]{%\n"
"    \\par%\n"
"    \\tabletail{\\hline}%\n"
"    \\tablelasttail{\\hline}%\n"
"    \\tablehead{}%\n"
"    \\tablefirsthead{\\multicolumn{2}{l}{\\hspace{-6pt}\\bfseries\\fontseries{bc}\\selectfont\\color{darkgray} #1}\\\\[1ex]}%\n"
"    \\begin{xtabular}{|>{\\raggedleft\\hspace{0pt}}p{0.25\\textwidth}|%\n"
"                          p{0.705\\textwidth}|}%\n"
"    \\hline%\n"
"}{%\n"
"    \\end{xtabular}%\n"
"    \\tablefirsthead{}%\n"
"    \\vspace{6pt}%\n"
"}\n"
"\n"
"% Used by template parameter lists\n"
"\\newenvironment{DoxyTemplParams}[1]{%\n"
"    \\par%\n"
"    \\tabletail{\\hline}%\n"
"    \\tablelasttail{\\hline}%\n"
"    \\tablehead{}%\n"
"    \\tablefirsthead{\\multicolumn{2}{l}{\\hspace{-6pt}\\bfseries\\fontseries{bc}\\selectfont\\color{darkgray} #1}\\\\[1ex]}%\n"
"    \\begin{xtabular}{|>{\\raggedleft\\hspace{0pt}}p{0.25\\textwidth}|%\n"
"                          p{0.705\\textwidth}|}%\n"
"    \\hline%\n"
"}{%\n"
"    \\end{xtabular}%\n"
"    \\tablefirsthead{}%\n"
"    \\vspace{6pt}%\n"
"}\n"
"\n"
"% Used for member lists\n"
"\\newenvironment{DoxyCompactItemize}{%\n"
"  \\begin{itemize}%\n"
"    \\setlength{\\itemsep}{-3pt}%\n"
"    \\setlength{\\parsep}{0pt}%\n"
"    \\setlength{\\topsep}{0pt}%\n"
"    \\setlength{\\partopsep}{0pt}%\n"
"}{%\n"
"  \\end{itemize}%\n"
"}\n"
"\n"
"% Used for member descriptions\n"
"\\newenvironment{DoxyCompactList}{%\n"
"  \\begin{list}{}{%\n"
"    \\setlength{\\leftmargin}{0.5cm}%\n"
"    \\setlength{\\itemsep}{0pt}%\n"
"    \\setlength{\\parsep}{0pt}%\n"
"    \\setlength{\\topsep}{0pt}%\n"
"    \\renewcommand{\\makelabel}{\\hfill}%\n"
"  }%\n"
"}{%\n"
"  \\end{list}%\n"
"}\n"
"\n"
"% Used for reference lists (@bug, @deprecated, @todo, etc.)\n"
"\\newenvironment{DoxyRefList}{%\n"
"  \\begin{list}{}{%\n"
"    \\setlength{\\labelwidth}{10pt}%\n"
"    \\setlength{\\leftmargin}{\\labelwidth}%\n"
"    \\addtolength{\\leftmargin}{\\labelsep}%\n"
"    \\renewcommand{\\makelabel}{\\xreflabel}%\n"
"  }%\n"
"}{%\n"
"  \\end{list}%\n"
"}\n"
"\n"
"% Used by @bug, @deprecated, @todo, etc.\n"
"\\newenvironment{DoxyRefDesc}[1]{%\n"
"  \\begin{list}{}{%\n"
"    \\renewcommand\\makelabel[1]{\\textbf{##1}}%\n"
"    \\settowidth\\labelwidth{\\makelabel{#1}}%\n"
"    \\setlength\\leftmargin{\\labelwidth+\\labelsep}%\n"
"  }%\n"
"}{%\n"
"  \\end{list}%\n"
"}\n"
"\n"
"% Used by parameter lists and simple sections\n"
"\\newenvironment{Desc}\n"
"{\\begin{list}{}{%\n"
"    \\settowidth{\\labelwidth}{40pt}%\n"
"    \\setlength{\\leftmargin}{\\labelwidth}%\n"
"    \\setlength{\\parsep}{0pt}%\n"
"    \\setlength{\\itemsep}{-4pt}%\n"
"    \\renewcommand{\\makelabel}{\\entrylabel}%\n"
"  }\n"
"}{%\n"
"  \\end{list}%\n"
"}\n"
"\n"
"% Used by tables\n"
"\\newcommand{\\PBS}[1]{\\let\\temp=\\\\#1\\let\\\\=\\temp}%\n"
"\\newlength{\\tmplength}%\n"
"\\newenvironment{TabularC}[1]%\n"
"{%\n"
"\\setlength{\\tmplength}%\n"
"     {\\linewidth/(#1)-\\tabcolsep*2-\\arrayrulewidth*(#1+1)/(#1)}%\n"
"      \\par\\begin{xtabular*}{\\linewidth}%\n"
"             {*{#1}{|>{\\PBS\\raggedright\\hspace{0pt}}p{\\the\\tmplength}}|}%\n"
"}%\n"
"{\\end{xtabular*}\\par}%\n"
"\n"
"% Used for member group headers\n"
"\\newenvironment{Indent}{%\n"
"  \\begin{list}{}{%\n"
"    \\setlength{\\leftmargin}{0.5cm}%\n"
"  }%\n"
"  \\item[]\\ignorespaces%\n"
"}{%\n"
"  \\unskip%\n"
"  \\end{list}%\n"
"}\n"
"\n"
"% Used when hyperlinks are turned off\n"
"\\newcommand{\\doxyref}[3]{%\n"
"  \\textbf{#1} (\\textnormal{#2}\\,\\pageref{#3})%\n"
"}\n"
"\n"
"% Used for syntax highlighting\n"
"\\definecolor{comment}{rgb}{0.5,0.0,0.0}\n"
"\\definecolor{keyword}{rgb}{0.0,0.5,0.0}\n"
"\\definecolor{keywordtype}{rgb}{0.38,0.25,0.125}\n"
"\\definecolor{keywordflow}{rgb}{0.88,0.5,0.0}\n"
"\\definecolor{preprocessor}{rgb}{0.5,0.38,0.125}\n"
"\\definecolor{stringliteral}{rgb}{0.0,0.125,0.25}\n"
"\\definecolor{charliteral}{rgb}{0.0,0.5,0.5}\n"
"\\definecolor{vhdldigit}{rgb}{1.0,0.0,1.0}\n"
"\\definecolor{vhdlkeyword}{rgb}{0.43,0.0,0.43}\n"
"\\definecolor{vhdllogic}{rgb}{1.0,0.0,0.0}\n"
"\\definecolor{vhdlchar}{rgb}{0.0,0.0,0.0}\n"
