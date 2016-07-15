! -*- coding: utf-8 -*-
! ==============================================================================
!   DANISH:  Language Definition File
!
!   Derived from English.h dated 20160608 by Thomas Bøvith (2016)
!
!   Supplied for use with Inform 6 -- Release 6.12.1 -- Serial number 160605
!
!   Copyright Graham Nelson 1993-2004 and David Griffith 2012-2016
!
!   This code is licensed under either the traditional Inform license as
!   described by the DM4 or the Artistic License version 2.0.  See the
!   file COPYING in the distribution archive or at
!   https://github.com/DavidGriffith/inform6lib/
!
!   This file is automatically Included in your game file by "parserm".
!   Strictly, "parserm" includes the file named in the "language__" variable,
!   whose contents can be defined by+language_name=XXX compiler setting (with a
!   default of "english").
!
!   Define the constant DIALECT_US before including "Parser" to obtain American
!   English.
! ==============================================================================

System_file;

#Ifndef LIBRARY_ENGLISH;	! if this file is already included,
				! don't try to include it again.

! ------------------------------------------------------------------------------
!   Part I.   Preliminaries
! ------------------------------------------------------------------------------

Constant EnglishNaturalLanguage;    ! Needed to keep old pronouns mechanism

Class   CompassDirection
  with  number 0, article "the",
        description [;
            if (location provides compass_look && location.compass_look(self)) rtrue;
            if (self.compass_look()) rtrue;
            L__M(##Look, 7, self);
        ],
        compass_look false,
        parse_name [; return -1; ]
  has   scenery;

Object Compass "compass" has concealed;

#Ifndef WITHOUT_DIRECTIONS;
CompassDirection -> n_obj  with short_name "nord",     door_dir n_to,
                                name 'n//' 'nord';
CompassDirection -> s_obj  with short_name "syd",      door_dir s_to,
                                name 's//' 'syd';
CompassDirection -> e_obj  with short_name "øst",      door_dir e_to,
                                name 'e//' 'ø//' 'øst';
CompassDirection -> w_obj  with short_name "vest",     door_dir w_to,
                                name 'w//' 'v//' 'vest';
CompassDirection -> ne_obj with short_name "nordøst",  door_dir ne_to,
                                name 'ne' 'nø' 'nordøst';
CompassDirection -> nw_obj with short_name "nordvest", door_dir nw_to,
                                name 'nw' 'nv' 'nordvest';
CompassDirection -> se_obj with short_name "sydøst",   door_dir se_to,
                                name 'se' 'sø' 'sydøst';
CompassDirection -> sw_obj with short_name "sydvest",  door_dir sw_to,
                                name 'sw' 'sv' 'sydvest';
CompassDirection -> u_obj  with short_name "op",       door_dir u_to,
                                name 'u//' 'op';
CompassDirection -> d_obj  with short_name "ned",      door_dir d_to,
                                name 'd//' 'ned';
#endif; ! WITHOUT_DIRECTIONS

CompassDirection -> in_obj  with short_name "ind",     door_dir in_to;
CompassDirection -> out_obj with short_name "ud",      door_dir out_to;

! ------------------------------------------------------------------------------
!   Part II.   Vocabulary
! ------------------------------------------------------------------------------

Constant AGAIN1__WD     = 'igen';
Constant AGAIN2__WD     = 'g//';
Constant AGAIN3__WD     = 'igen';
Constant OOPS1__WD      = 'oops';
Constant OOPS2__WD      = 'o//';
Constant OOPS3__WD      = 'ups';
Constant UNDO1__WD      = 'undo';
Constant UNDO2__WD      = 'fortryd';
Constant UNDO3__WD      = 'fortryd';

Constant ALL1__WD       = 'alle';
Constant ALL2__WD       = 'hver';
Constant ALL3__WD       = 'enhver';
Constant ALL4__WD       = 'allesammen';
Constant ALL5__WD       = 'alt';
Constant AND1__WD       = 'og';
Constant AND2__WD       = 'samt';
Constant AND3__WD       = 'også';
Constant BUT1__WD       = 'men ikke';
Constant BUT2__WD       = 'undtagen';
Constant BUT3__WD       = 'på nær';
Constant ME1__WD        = 'jeg';
Constant ME2__WD        = 'mig';
Constant ME3__WD        = 'mig selv';
Constant OF1__WD        = 'af';
Constant OF2__WD        = 'blandt';
Constant OF3__WD        = 'ud af';
Constant OF4__WD        = 'af';
Constant OTHER1__WD     = 'andre';
Constant OTHER2__WD     = 'anden';
Constant OTHER3__WD     = 'andet';
Constant THEN1__WD      = 'så';
Constant THEN2__WD      = 'derefter';
Constant THEN3__WD      = 'og';

Constant NO1__WD        = 'n//';
Constant NO2__WD        = 'nej';
Constant NO3__WD        = 'næ';
Constant YES1__WD       = 'y//';
Constant YES2__WD       = 'ja';
Constant YES3__WD       = 'jo';

Constant AMUSING__WD    = 'amusing';
Constant FULLSCORE1__WD = 'fullscore';
Constant FULLSCORE2__WD = 'full';
Constant QUIT1__WD      = 'quit';
Constant QUIT2__WD      = 'afslut';
Constant RESTART__WD    = 'restart';
Constant RESTORE__WD    = 'restore';

! Danish has two grammatical genders: common (fælleskøn/utrum) and neuter
! (intetkøn/neutrum), and two natural genders: masculine and feminine.

Array LanguagePronouns table

  ! word        possible GNAs                   connected
  !             to follow:                      to:
  !             a     i
  !             s  p  s  p
  !             mfnmfnmfnmfn

    'han'     $$100000100000                    NULL
    'hun'     $$010000010000                    NULL
    'den'     $$001100001100                    NULL
    'det'     $$001000001000                    NULL
    'dem'     $$000111000111                    NULL;

Array LanguageDescriptors table

  ! word        possible GNAs   descriptor      connected
  !             to follow:      type:           to:
  !             a     i
  !             s  p  s  p
  !             mfnmfnmfnmfn

    'min'     $$001100001100    POSSESS_PK      0
    'mit'     $$001000001000    POSSESS_PK      0
    'mine'    $$000111000111    POSSESS_PK      0
    'hans'    $$111111111111    POSSESS_PK      'han'
    'hendes'  $$111111111111    POSSESS_PK      'hende'
    'deres'   $$111111111111    POSSESS_PK      'dem'
    'dens'    $$111111111111    POSSESS_PK      'den'
    'dets'    $$111111111111    POSSESS_PK      'det'
    'en'      $$001100001100    INDEFART_PK     NULL
    'et'      $$001000001000    INDEFART_PK     NULL
    'nogen'   $$000111000111    INDEFART_PK     NULL
    'tændt'   $$111111111111    light           NULL
    'tændt'   $$111111111111    light           NULL
    'slukket' $$111111111111    (-light)        NULL;

Array LanguageNumbers table
    'en' 1 'et' 1 'to' 2 'par' 2 'tre' 3 'fire' 4 'fem' 5
    'seks' 6 'syv' 7 'otte' 8 'ni' 9 'ti' 10
    'elleve' 11 'tolv' 12 'tretten' 13 'fjorten' 14 'femten' 15
    'seksten' 16 'sytten' 17 'atten' 18 'nitten' 19 'tyve' 20;

! ------------------------------------------------------------------------------
!   Part III.   Translation
! ------------------------------------------------------------------------------

[ LanguageToInformese;
];

! ------------------------------------------------------------------------------
!   Part IV.   Printing
! ------------------------------------------------------------------------------

Constant LanguageAnimateGender   = male;
Constant LanguageInanimateGender = neuter;

Constant LanguageContractionForms = 1;     ! Danish has one.

[ LanguageContraction text x;
  x = text; ! Just to avoid compiler warning
  return 0;
];

Array LanguageArticles -->

 !   Contraction form 0:
 !   Cdef   Def    Indef

     "Den " "den " "en "     ! Masuline, feminine, utrum
     "Det " "det " "et "     ! Neutrum
     "De "  "de "  "nogle "  ! Plural

                   !             a           i
                   !             s     p     s     p
                   !             m f n m f n m f n m f n

Array LanguageGNAsToArticles --> 0 0 0 1 1 1 0 0 0 1 1 1;

[ LanguageDirection d;
    switch (d) {
      n_to:    print "nord";
      s_to:    print "syd";
      e_to:    print "øst";
      w_to:    print "vest";
      ne_to:   print "nordøst";
      nw_to:   print "nordvest";
      se_to:   print "sydøst";
      sw_to:   print "sydvest";
      u_to:    print "op";
      d_to:    print "ned";
      in_to:   print "ind";
      out_to:  print "ud";
      default: return RunTimeError(9,d);
    }
];

[ LanguageNumber n force_neuter   f r;
! From number to text string representatation (n = [-32767;32767])
    f = 0;
    if (n == 0) { print "nul"; rfalse; }
    if (n < 0) { print "minus "; n = -n; }
    if (n >= 1000) {
        if (f == 1) print ", ";
        LanguageNumber(n/1000, true, 0, 0);
        print " tusinde";
        n = n%1000;
        f = 1;
    }
    if (n >= 100) {
        if (f == 1) print ", ";
        LanguageNumber(n/100, true, 0, 0);
        print " hundrede";
        n = n%100;
        f = 1;
    }
    if (n == 0) rfalse;
    if (n < 100) {
        r = n%10;
        if (f == 1) print " og ";
        if (n > 19 && r ~= 0) {
            (LanguageNumber) (r);
            print " og ";
            n = n - r;
        }
    }
    switch (n) {
     1:    if (force_neuter) print "et"; else print "en";
     2:    print "to";
     3:    print "tre";
     4:    print "fire";
     5:    print "fem";
     6:    print "seks";
     7:    print "syv";
     8:    print "otte";
     9:    print "ni";
     10:   print "ti";
     11:   print "elleve";
     12:   print "tolv";
     13:   print "tretten";
     14:   print "fjorten";
     15:   print "femten";
     16:   print "seksten";
     17:   print "sytten";
     18:   print "atten";
     19:   print "nitten";
     20 to 99:
        switch(n/10) {
         2: print "tyve";
         3: print "tredive";
         4: print "fyrre";
         5: print "halvtres";
         6: print "treds";
         7: print "halvfjerds";
         8: print "firs";
         9: print "halvfems";
        }
    }
];

[ LanguageTimeOfDay hours mins;
    hours = hours % 24;
    mins = mins % 60;
    print hours/10, hours%10, ":", mins/10, mins%10;
];

[ LanguageVerb i;
    switch (i) {
      'i//','stat','status': print "gør status";
      'l//','k//': print "se";
      'x//': print "undersøg";
      'z//': print "vent";
      default: rfalse;
    }
    rtrue;
];

! ----------------------------------------------------------------------------
!  LanguageVerbIsDebugging is called by SearchScope.  It should return true
!  if word w is a debugging verb which needs all objects to be in scope.
! ----------------------------------------------------------------------------

#Ifdef DEBUG;
[ LanguageVerbIsDebugging w;
    if (w == 'purloin' or 'tree' or 'abstract'
                       or 'gonear' or 'scope' or 'showobj')
        rtrue;
    rfalse;
];
#Endif;

! ----------------------------------------------------------------------------
!  LanguageVerbLikesAdverb is called by PrintCommand when printing an UPTO_PE
!  error or an inference message.  Words which are intransitive verbs, i.e.,
!  which require a direction name as an adverb ('walk west'), not a noun
!  ('I only understood you as far as wanting to touch /the/ ground'), should
!  cause the routine to return true.
! ----------------------------------------------------------------------------

[ LanguageVerbLikesAdverb w;
    if (w == 'se' or 'gå' or 'skub')
        rtrue;
    rfalse;
];

! ----------------------------------------------------------------------------
!  LanguageVerbMayBeName is called by NounDomain when dealing with the
!  player's reply to a "Which do you mean, the short stick or the long
!  stick?" prompt from the parser. If the reply is another verb (for example,
!  LOOK) then then previous ambiguous command is discarded /unless/
!  it is one of these words which could be both a verb /and/ an
!  adjective in a 'name' property.
! ----------------------------------------------------------------------------

[ LanguageVerbMayBeName w;
    if (w == 'long' or 'short' or 'normal'
                    or 'brief' or 'full' or 'verbose')
        rtrue;
    rfalse;
];

Constant NKEY__TX       = "N = næste emne";
Constant PKEY__TX       = "F = forrige emne";
Constant QKEY1__TX      = "  Q = tilbage til spillet";
Constant QKEY2__TX      = "Q = forrige menu";
Constant RKEY__TX       = "ENTER = læs emne";

Constant NKEY1__KY      = 'N';
Constant NKEY2__KY      = 'n';
Constant PKEY1__KY      = 'F';
Constant PKEY2__KY      = 'f';
Constant QKEY1__KY      = 'Q';
Constant QKEY2__KY      = 'q';

Constant SCORE__TX      = "Score: ";
Constant MOVES__TX      = "Træk: ";
Constant TIME__TX       = "Tid: ";
Constant CANTGO__TX     = "Du kan ikke gå den vej.";
Constant FORMER__TX     = "dit tidligere selv";
Constant MYFORMER__TX   = "mit tidligere selv";
Constant YOURSELF__TX   = "dig selv";
Constant MYSELF__TX     = "mig selv";
Constant YOU__TX        = "Du";
Constant DARKNESS__TX   = "Mørke";

Constant THOSET__TX     = "dem";
Constant THAT__TX       = "den";
Constant OR__TX         = " eller ";
Constant NOTHING__TX    = "ingenting";
Constant IS__TX         = " er";
Constant ARE__TX        = " er";
Constant IS2__TX        = "er ";
Constant ARE2__TX       = "er ";
Constant WAS__TX        = " var";
Constant WERE__TX       = " var";
Constant WAS2__TX       = "var ";
Constant WERE2__TX      = "var ";
Constant AND__TX        = " og ";
Constant WHOM__TX       = "som ";
Constant WHICH__TX      = "som ";
Constant COMMA__TX      = ", ";
Constant COLON__TX      = ": ";

! ----------------------------------------------------------------------------
! FYI on nominative pronouns versus accusative pronouns...
! Consider the sentence "She hit him.".
! "She" is in the nominative case.  It appears at the beginning of a sentence.
! "him" is in the accusative case.  It won't appear at the beginning.
! ----------------------------------------------------------------------------

! Accusative
[ ThatOrThose obj;
    if (obj == player) {
	if (player provides narrative_voice) {
	    if (player.narrative_voice == 1) { print "mig"; return; }
	    if (player.narrative_voice == 3) { CDefart(player); return; }
	}
	print "du";
	return;
    }
    if (obj has pluralname)       { print "dem"; return; }
    if (obj has female)           { print "hende"; return; }
    if (obj has male or animate)
        if (obj hasnt neuter)     { print "ham"; return; }
    print "den";
];

! Accusative
[ ItOrThem obj;
    if (obj == player) {
	if (player provides narrative_voice) {
	    if (player.narrative_voice == 1) { print "mig selv"; return; }
	    if (player.narrative_voice == 3) { CDefart(player); return; }
	}
	print "dig selv";
	return;
    }
    if (obj has pluralname)       { print "dem"; return; }
    if (obj has female)           { print "hende"; return; }
    if (obj has male or animate)
        if (obj hasnt neuter)     { print "ham"; return; }
    print "den";
];

! Nominative
[ CThatOrThose obj;
    if (obj == player) {
	if (player provides narrative_voice) {
	    if (player.narrative_voice == 1) { print "Jeg"; return; }
	    if (player.narrative_voice == 3) { CDefart(player); return; }
	}
	print "Dig";
	return;
    }
    if (obj has pluralname)		{ print "Dem"; return; }
    if (obj has female)			{ print "Hende"; return; }
    if (obj has male or animate) {
        if (obj hasnt neuter)		{ print "Ham"; return; }
    }
    print "Den";
];

! Nominative
[ CTheyreorThats obj;
    if (obj == player) {
	if (player provides narrative_voice) {
	    if (player.narrative_voice == 1) { print "Jeg er"; return; }
	    if (player.narrative_voice == 3) { CDefart(player); print "s"; return; }
	}
	print "Du er";
	return;
    }
    if (obj has pluralname)		{ print "De er"; return; }
    if (obj has female)			{ print "Hun er"; return; }
    if (obj has male or animate) {
        if (obj hasnt neuter)		{ print "Han er"; return; }
    }
    print "Det er";
];

[ IsOrAre obj;
    if (player provides narrative_tense && player.narrative_tense == PAST_TENSE) {
        if (obj has pluralname || obj == player) print "var"; else print "var";
        return;
    }
    if (obj has pluralname || obj == player) print "er"; else print "er";
    return;
];

[ nop x; x = x; ];      ! print rule to absorb unwanted return value

[ SubjectNotPlayer obj reportage v2 v3 past;
    if (past && player provides narrative_tense && player.narrative_tense == PAST_TENSE) {
        v2 = past;
        v3 = past;
    }
    if (reportage && actor ~= player) {
        L__M(##Miscellany, 60, actor);
        if (obj == actor) {
            print (theActor) obj, " ", (string) v3;
            return;
        }
        else
            if (obj has pluralname) {
                print (the) obj, " ", (string) v2;
                return;
            }
            else {print (the) obj, " ", (string) v3; return;}
    }
   else
        if (obj has pluralname) { print (The) obj, " ", (string) v2; return;}
        else                    { print (The) obj, " ", (string) v3; return;}
];

[ CSubjectVoice obj v1 v2 v3 past;
    if (past && player provides narrative_tense && player.narrative_tense == PAST_TENSE) {
        v1 = past;
        v2 = past;
        v3 = past;
    } else {
        if (v2 == 0) v2 = v1;
        if (v3 == 0) v3 = v1;
    }
    if (obj ~= player) { print (string) v3; return; }

    if (player provides narrative_voice) switch (player.narrative_voice) {
      1:  print (string) v1; return;
      2:  ! Do nothing.
      3:  print (string) v3; return;
      default: RunTimeError(16, player.narrative_voice);
    }

    print (string) v2; return;
];

[ CSubjectVerb obj reportage nocaps v1 v2 v3 past;
    if (past && player provides narrative_tense && player.narrative_tense == PAST_TENSE) {
        v1 = past;
        v2 = past;
        v3 = past;
    } else {
        if (v2 == 0) v2 = v1;
        if (v3 == 0) v3 = v1;
    }
    if (obj == player) {
        if (player provides narrative_voice) switch (player.narrative_voice) {
          1:  print "Jeg ", (string) v1; return;
          2:  ! Do nothing.
          3:  CDefart(player);
              print " ", (string) v3; return;
          default: RunTimeError(16, player.narrative_voice);
        }
        if (nocaps) { print "du ", (string) v2; return; }
	print "Du ", (string) v2; return;
    }
    SubjectNotPlayer(obj, reportage, v2, v3);
];

[ CSubjectIs obj reportage nocaps;
    if (obj == player) {
        if (player provides narrative_voice) switch (player.narrative_voice) {
          1:  Tense("I'm", "I was"); return;
          2:  ! Do nothing.
          3:  CDefart(player);
              Tense(" is", " was"); return;
          default: RunTimeError(16, player.narrative_voice);
        }
        if (nocaps) Tense("you're", "you were");
        else Tense("You're", "You were");
        return;
    }
    SubjectNotPlayer(obj, reportage, "are", "is", "was");
];

[ CSubjectIsnt obj reportage nocaps;
    if (obj == player) {
        if (player provides narrative_voice) switch (player.narrative_voice) {
          1:  Tense("I'm not", "I wasn't"); return;
          2:  ! Do nothing.
          3:  CDefart(player);
              Tense(" isn't", " wasn't"); return;
          default: RunTimeError(16, player.narrative_voice);
        }
        if (nocaps) Tense("you aren't", "you weren't");
        else Tense("You aren't", "You weren't");
	return;
    }
    SubjectNotPlayer(obj, reportage, "aren't", "isn't", "wasn't");
];

[ CSubjectHas obj reportage nocaps;
    if (obj == player) {
        if (player provides narrative_voice) switch (player.narrative_voice) {
          1:  Tense("I've", "I had"); return;
          2:  ! Do nothing.
          3:  CDefart(player);
              Tense(" has", " had"); return;
          default: RunTimeError(16, player.narrative_voice);
        }
        if (nocaps) Tense("you've", "you'd");
        else Tense("You've", "You'd");
        return;
    }
    SubjectNotPlayer(obj, reportage, "have", "has", "had");
];

[ CSubjectWill obj reportage nocaps;
    if (obj == player) {
        if (player provides narrative_voice) switch (player.narrative_voice) {
          1:  Tense("I'll", "I would've"); return;
          2:  ! Do nothing.
          3:  CDefart(player);
              Tense(" will", " would've"); return;
          default: RunTimeError(16, player.narrative_voice);
        }
        if (nocaps) Tense("you'll", "you'd");
        else Tense("You'll", "You'd");
        return;
    }
    SubjectNotPlayer(obj, reportage, "will", "will", "would");
];

[ CSubjectCan obj reportage nocaps;
    CSubjectVerb(obj, reportage, nocaps, "can", 0, "can", "could");
];

[ CSubjectCant obj reportage nocaps;
    CSubjectVerb(obj, reportage, nocaps, "can't", 0, "can't", "couldn't");
];

[ CSubjectDont obj reportage nocaps;
    CSubjectVerb(obj, reportage, nocaps, "don't", 0, "doesn't", "didn't");
];


[ OnesSelf obj;
    if (obj == player) {
        if (player provides narrative_voice) switch(player.narrative_voice) {
            1:  print (string) MYSELF__TX; return;
            2:  ! Do nothing.
            3:  if (obj has female) {print "herself"; return;}
                print "himself"; return;
          default: RunTimeError(16, player.narrative_voice);
        }
        print "yourself"; return;
    }
    if (obj has male) { print "himself"; return; }
    if (obj has female) {print "herself"; return; }
    print "itself"; return;
];


[ Possessive obj caps;
    if (obj == player) {
        if (player provides narrative_voice) switch(player.narrative_voice) {
          1:  if (caps) print "M"; else print "m"; print "y"; return;
          2:  ! Do nothing.
          3:  CDefart(player);
              print "'s"; return;
          default: RunTimeError(16, player.narrative_voice);
        }
        if (caps) print "Y"; else print "y";
        print "our"; return;
    }
    if (caps) print "H"; else print "h";
    if (obj has male) { print "is"; return; }
    if (obj has female) { print "er"; return; }
    if (caps) print "I"; else { print "i"; print "ts"; return; }
];

[ PossessiveCaps obj;
    Possessive(obj, true);
];

[ theActor obj;
    if (obj == player) {
        if (obj provides narrative_voice) {
            switch (obj.narrative_voice) {
              1:  print "jeg"; return;
              2:  ! Do nothing.
              3:  if (obj has neuter) { print "den"; return; }
                  if (obj has female) { print "hun"; return; }
                  print "han"; return;
              default: RunTimeError(16, player.narrative_voice);
            }
        }
        print "du"; return;
    }
    if (obj has pluralname)       { print "de"; return; }
    if (obj has female)           { print "hun"; return; }
    if (obj has male or animate)
        if (obj hasnt neuter)     { print "han"; return; }
                                    print "den";
];

[ SupportObj obj s1 s2;
    if (obj has supporter)          print (string) s1;
    else                            print (string) s2;
];

[ PluralObj obj s1 s2 past;
    if (player provides narrative_tense && player.narrative_tense == PAST_TENSE) {
        print (string) past;
        return;
    }
    if (obj has pluralname)         print (string) s1;
    else                            print (string) s2;
];

! ----------------------------------------------------------------------------
! Tense is a little helper function to present the correct tense of a
! verb.  The first parameter is the verb in present tense.  The second
! parameter is the verb in past tense.  If the second parameter is
! omitted, then nothing will be printed if the appropriate tense is past.
! ----------------------------------------------------------------------------
[ Tense present past;
    if (player provides narrative_tense && player.narrative_tense == PAST_TENSE) {
        if (past == false) return;
        print (string) past;
    }
    else
        print (string) present;
];

[ DecideAgainst;
    CSubjectVerb(actor, false, false, "decide",0,"decides","decided");
    print " that";
    Tense("'s not", " wasn't");
    " such a good idea.";
];

#Ifdef TARGET_ZCODE;

[ LowerCase c;    ! for ZSCII matching ISO 8859-1
   switch (c) {
     'A' to 'Z':                            c = c + 32;
     202, 204, 212, 214, 221:               c--;
     217, 218:                              c = c - 2;
     158 to 160, 167, 168, 208 to 210:      c = c - 3;
     186 to 190, 196 to 200:                c = c - 5 ;
     175 to 180:                            c = c - 6;
   }
   return c;
];

[ UpperCase c;    ! for ZSCII matching ISO 8859-1
   switch (c) {
     'a' to 'z':                            c = c - 32;
     201, 203, 211, 213, 220:               c++;
     215, 216:                              c = c + 2;
     155 to 157, 164, 165, 205 to 207:      c = c + 3;
     181 to 185, 191 to 195:                c = c + 5 ;
     169 to 174:                            c = c + 6;
   }
   return c;
];

#Ifnot; ! TARGET_GLULX

[ LowerCase c; return glk_char_to_lower(c); ];
[ UpperCase c; return glk_char_to_upper(c); ];

#Endif; ! TARGET_



[ LanguageLM n x1 x2;
  Answer,Ask:
            print "Der ";
            Tense("er", "var");
            " intet svar.";
! Ask:      see Answer
  Attack:   print "Vold ";
            Tense("er", "var");
            " ikke løsningen her.";
  Blow:     CSubjectCant(actor,true);
            " forvente, at det giver mening at blæse på ", (thatorthose) x1, ".";
  Burn: switch (n) {
        1:  print "Den farefulde handling vil";
            Tense(" ikke medføre", "le ikke medføre");
            " noget godt.";
        2:  DecideAgainst();
    }
  Buy:      print "Desværre ";
            Tense("er ", "var ");
            print (ThatOrThose) x1;
            " ikke til salg.";
  Climb: switch (n) {
        1:  print "At klatre ", (ThatOrThose) x1, " vil";
            Tense(" opnå", "le opnå");
            " meget lidt.";
        2:  DecideAgainst();
    }
  Close: switch (n) {
        1:  CSubjectIs(x1,true);
            print " ikke noget ", (theActor) actor;
            Tense(" kan lukke", " kunne have lukket");
            ".";
        2:  CSubjectIs(x1,true); " allerede lukket.";
        3:  CSubjectVerb(actor,false,false,"lukke",0,"lukker","lukket");
            " ", (the) x1, ".";
        4:  "(efter at have lukket ", (the) x1, ")";
    }
  CommandsOff: switch (n) {
        1: "[Command recording off.]";
        #Ifdef TARGET_GLULX;
        2: "[Command recording already off.]";
        #Endif; ! TARGET_
    }
  CommandsOn: switch (n) {
        1: "[Command recording on.]";
        #Ifdef TARGET_GLULX;
        2: "[Commands are currently replaying.]";
        3: "[Command recording already on.]";
        4: "[Command recording failed.]";
        #Endif; ! TARGET_
    }
  CommandsRead: switch (n) {
        1: "[Replaying commands.]";
        #Ifdef TARGET_GLULX;
        2: "[Commands are already replaying.]";
        3: "[Command replay failed.  Command recording is on.]";
        4: "[Command replay failed.]";
        5: "[Command replay complete.]";
        #Endif; ! TARGET_
    }
  Consult:  CSubjectVerb(actor,true,false,"finder",0,"finder","fandt");
            print " ingenting af interesse i ";
            if (x1 == player) { OnesSelf(x1); ".";}
            else print_ret (the) x1, ".";
  Cut: switch (n) {
        1:  print "At skære i ", (ThatOrThose) x1;
            Tense("virker", "virkede");
            " meningsløst.";
        2:  DecideAgainst();
    }
  Dig:      print "At grave ";
            Tense("vil", "ville");
            " være meningsløst her.";
  Disrobe: switch (n) {
        1:  CSubjectIsnt(actor,true); " har ikke ", (ThatOrThose) x1, " på.";
        2:  CSubjectVerb(actor,false,false,"tager",0,"tager", "tog");
            " ", (the) x1, " af.";
    }
  Drink:    print "Der";
            Tense(" findes", " fandtes");
            " ingen ting værd at drikke her.";
  Drop: switch (n) {
        1:  CSubjectIs(x1,true); " er her allerede.";
        2:  CSubjectVerb(actor, false, false, "har ikke", 0, "har ikke",
                         "havde ikke");
            " ", (the) x1, ".";
        3:  "(tager først ", (the) x1, " af)";
        4:  "Smidt.";
    }
  Eat: switch (n) {
        1:  CSubjectIs(x1,true); " er uspiselig.";
        2:  CSubjectVerb(actor,false,false,"spiser",0,"spiser", "spiste"); print " ", (the) x1;
                if (actor == player) ". Ikke værst."; else ".";
    }
  EmptyT: switch (n) {
        1:  CSubjectCant(x1,true); " indeholde noget.";
        2:  CSubjectIs(x1,true); " lukket.";
        3:  CSubjectIs(x1,true); " allerede tom.";
        4:  print "Det ville ikke ";
            Tense("tom", "har tømt");
            " noget.";
    }
  Enter: switch (n) {
        1:  print "Men "; CSubjectIs(actor,true,true);
            " allerede ", (nop) SupportObj(x1,"på ","i "), (the) x1, ".";
        2:  CSubjectIs(x1,true);
            print " ikke noget som ", (theActor) actor;
            Tense(" kan ", " kunne ");
            switch (x2) {
              'stå':  "stå på.";
              'sid':    "sidde på.";
              'lig':    "ligge på.";
              default:  "gå ind i.";
            }
        3:  CSubjectCant(actor,true);
            " gå ind i den lukkede ", (name) x1, ".";
        4:  CSubjectCan(actor,true);
            " kun gå ind i noget fritstående.";
        5:  CSubjectVerb(actor,false,false,"går",0,"går","gik");
            SupportObj(x1," op på"," ind i"); " ", (the) x1, ".";
        6:  "(kommer ", (nop) SupportObj(x1,"af","ud af"), " ", (the) x1, ")";
        7:  if (x1 has supporter) "(spinger op på ", (the) x1, ")";
            if (x1 has container) "(går ind i ", (the) x1, ")";
                                  "(går ind i ", (the) x1, ")";
    }
  Examine: switch (n) {
        1:  "Mørke, substantiv. Fuldstændigt eller næsten fuldstændigt fravær af dagslys eller lys fra lamper, lygter m.m.";
        2:  CSubjectVerb(actor,true,false,"ser",0,"ser","så");
            " intet bemærkelsesværdigt ved ", (the) x1, ".";
        3:  CSubjectIs(x1,true);
            Tense(" lige nu ");
            if (x1 has on) "tændt."; else "slukket.";
    }
  Exit: switch (n) {
        1:  print "Men ";
            CSubjectIsnt(actor,true,true);
            " inde i noget som helt i øjeblikket.";
        2:  CSubjectCant(actor,false);
            " forlader den lukkede ", (name) x1, ".";
        3:  CSubjectVerb(actor,false,false,"går",0,"går", "gik");
            print " ";
            SupportObj(x1,"ned af","ud af"); " ", (the) x1, ".";
        4:  CSubjectIsnt(actor,true);
            print " ";
            SupportObj(x1,"på","i"); " ", (the) x1, ".";
        5:  "(går først ", (nop) SupportObj(x1,"ned af","ud af"),
              " ", (the) x1, ")";
        6:  CSubjectVerb(actor,false,false,"står",0,"står","stod"); " op.";
    }
  Fill: switch (n) {
        1:  print "Der ";
            Tense("er", "var");
            " intet oplagt at fylde ", (the) x1, " med.";
        2:  print "At fylde ", (the) x1, " fra ", (the) x2;
            Tense(" giver", " gav");
            " ingen mening.";
    }
  FullScore: switch (n) {
        1:  if (deadflag) print "Scoren var "; else print "Scoren er ";
                "opgjort således:^";
        2:  "finde vigtige ting";
        3:  "besøge vigtige steder";
        4:  print "total (ud af ", MAX_SCORE; ")";
    }
  GetOff:   print "Men ";
            CSubjectIsnt(actor,true,true); " på ", (the) x1, " i øjeblikket.";
  Give: switch (n) {
        1:  CSubjectIsnt(actor,true); " bærer ikke ", (the) x1, ".";
        2:  CSubjectVerb(actor,false,false,"fumler",0,"fumler","fumlede");
            print " ", (the) x1, " i et stykke tid, men ";
            CSubjectVoice(actor,"opnår","opnår","opnår","opnåede");
            " ikke meget derved.";
        3:  CSubjectDont(x1,true); " lader ikke til at være interesseret.";
        4:  CSubjectVerb(actor,false,false,"giver",0,"giver","gav");
            " til ", (the) x1, ".";
    }
  Go: switch (n) {
        1:  CSubjectWill(actor,true);
            Tense(" må", " måtte");
                " klatre ", (nop) SupportObj(x1,"ned","ned af"), " ", (the) x1, " først.";
        2:  CSubjectCant(actor,true); " gå den vej.";
        3:  CSubjectIs  (actor,true); " kan ikke klatre op på ", (the) x1, ".";
        4:  CSubjectIs  (actor,true); " kan ikke klatre ned af ", (the) x1, ".";
        5:  CSubjectCant(actor,true); " fordi ", (the) x1, " ", (IsOrAre) x1, " er i vejen.";
        6:  CSubjectCant(actor,true); " fordi ", (the) x1, " ikke ", (nop) PluralObj(x1,"fører","fører","førte"), " nogen steder hen.";
        7:  CSubjectVerb(actor,false,false,"afgår",0,"afgår","afgik"); ".";
    }
  Insert: switch (n) {
        1:  CSubjectVerb(actor,true,false,"må",0,"må","måtte");
            print " have ", (the) x1, " før ", (theActor) actor;
            Tense(" kan", " kunne");
            " lægge ", (ItOrThem) x1, " ind i noget.";
        2:  CSubjectCant(x1,true); " indeholder ting.";
        3:  CSubjectIs  (x1,true); " lukket.";
        4:  CSubjectWill(actor,true);
            Tense(" må", " måtte");
            " tage ", (ItOrThem) x1, " af først.";
        5:  CSubjectCant(actor,true); " lægge noget ind i sig selv.";
        6:  "(tager først ", (ItOrThem) x1, " af)";
        7:  print "Der ";
            Tense(" er", " var");
            " ikke plads til mere i ", (the) x1, ".";
        8:  "Udført.";
        9:  CSubjectVerb(actor,false,false,"lægger",0,"lægger","lagde"); " ", (the) x1, " inden i ", (the) x2, ".";
    }
  Inv: switch (n) {
        1:  CSubjectIs  (actor,false); " har ingenting.";
        2:  CSubjectIs  (actor,false); print " har";
        3:  ":";
        4:  ".";
    }
  Jump: CSubjectVerb(actor,false,false,"hopper",0,"hopper","hoppede"); " lidt op og ned.";
  JumpIn:
        print "At hoppe i ", (the) x1, " ";
        Tense("ville medføre", "ville have medført");
        " intet her.";
  JumpOn:
        print "At hoppe op på ", (the) x1, " ";
        Tense("ville medføre", "ville have medført");
        " intet her.";
  JumpOver: switch (n) {
        1:  CSubjectVerb(actor,true,false,"opnår",0,"opnår","opnåede"); " intet ved dette.";
        2:  DecideAgainst();
    }
  Kiss:     "Du drømmer dig bort et øjeblik.";
  Listen:   CSubjectVerb(actor,true,false,"hører",0,"hører","hørte"); " ikke noget uventet.";
  ListMiscellany: switch (n) {
        1:  print " (lyser)";
        2:  print " (som ", (IsOrAre) x1, " lukket)";
        3:  print " (lukket og lyser)";
        4:  print " (som ", (IsOrAre) x1, " tom)";
        5:  print " (som og lyser)";
        6:  print " (som ", (IsOrAre) x1, " lukket og tom)";
        7:  print " (lukket, tom og lyser)";
        8:  print " (lyser og bæres";
        9:  print " (lyser";
        10: print " (bæres";
        11: print " (som ", (IsOrAre) x1, " ";
        12: print "åben";
        13: print "åben men tom";
        14: print "lukket";
        15: print "lukket og låst";
        16: print " og tom";
        17: print " (om ", (IsOrAre) x1, " tom)";
        18: print " indeholder ";
        19: print " (på ";
        20: print ", oven på ";
        21: print " (i ";
        22: print ", inden i ";
    }
  LMode1:   print " is now in its ";
            if (initial_lookmode == 1) print "normal ";
            "~brief~ printing mode, which gives long descriptions
             of places never before visited and short descriptions otherwise.";
  LMode2:   print " is now in its ";
            if (initial_lookmode ~= 1 or 3) print "normal ";
            "~verbose~ mode, which always gives long descriptions
             of locations (even if you've been there before).";
  LMode3:   print " is now in its ";
            if (initial_lookmode == 3) print "normal ";
            "~superbrief~ mode, which always gives short descriptions
             of locations (even if you haven't been there before).";
  Lock: switch (n) {
        1:  CSubjectDont(x1,true);
            print " noget som ", (theActor) actor;
            Tense(" kan", " kunne");
            " låse.";
        2:  CSubjectIs  (x1,true); " låst i øjeblikket.";
        3:  CSubjectWill(actor,true); " først lukke ", (the) x1, ".";
        4:  CSubjectDont(x1,true); " ser ud til at passe i låsen.";
        5:  CSubjectVerb(actor,false,false,"låser",0,"låser","låste"); " ", (the) x1, ".";
    }
  Look: switch (n) {
        1:  print " (på ", (the) x1, ")";
        2:  print " (i ", (the) x1, ")";
        3:  print " (som ", (object) x1, ")";
        4:  print "^På ", (the) x1;
            WriteListFrom(child(x1),
              ENGLISH_BIT+RECURSE_BIT+PARTINV_BIT+TERSE_BIT+CONCEAL_BIT+ISARE_BIT);
            ".";
        5,6:
            if (x1 ~= location) {
                if (x1 has supporter) print "^På "; else print "^I ";
                print (the) x1, " ", (theActor) actor, " ";
                Tense("kan", "kunne");
            }
            else { new_line; CSubjectCan(actor,false); }
            if (n == 5) print " også";
            print " se ";
            WriteListFrom(child(x1),
              ENGLISH_BIT+RECURSE_BIT+PARTINV_BIT+TERSE_BIT+CONCEAL_BIT+WORKFLAG_BIT);
            if (x1 ~= location) "."; else " her.";
        7:  CSubjectVerb(actor,true,false,"ser",0,"ser", "så"); " ingenting uventet i den retning.";
    }
  LookUnder: switch (n) {
        1:  print "Men det";
            Tense("er", " var");
            " mørkt.";
        2:  CSubjectVerb(actor,true,false,"finder",0,"finder", "fandt"); " ingenting af interesse.";
    }
  Mild:     "Akkurat, det tænkte jeg også.";
  Miscellany: switch (n) {
        1:  "(tager blot hensyn til de første seksten ting)^";
        2:  "Ingen ting at gøre!";
        3:  print " "; CSubjectVerb(player, false, false, "er død", "er død", "døde");
	    print " ";
        4:  print " "; CSubjectVerb(player, false, false, "har vundet", "har vundet", "vandt");
            print " ";
        5:  print "^Du kan RESTART, RESTORE et gemt spil";
            #Ifdef DEATH_MENTION_UNDO;
            print ", UNDO dit sidste træk";
            #Endif;
            if (TASKS_PROVIDED == 0) print ", vis FULL score for det spil";
            if (deadflag == 2 && AMUSING_PROVIDED == 0)
                print ", se nogle foreslag på AMUSING ting at prøve";
            SerialComma(3); print " eller QUIT?";
        6:  "[Spilfortolkeren understøtter desværre ikke ~undo~. Beklager!]";
            #Ifdef TARGET_ZCODE;
        7:  "~Undo~ fejlede. [Ikke alle spilfortolkere understøtter det.]";
            #Ifnot; ! TARGET_GLULX
        7:  "[Du kan ikke ~undo~ længere tilbage.]";
            #Endif; ! TARGET_
        8:  "Vælg et af svarene ovenfor.";
        9:  print "^Det ";
            Tense("er nu", "var");
            print " bælgmørkt ";
            Tense("her", "der");
            "!";
        10: "Undskyld mig?";
        11: "[Du kan ikke ~undo~ noget, som du ikke har gjort!]";
        12: "[Du kan desværre ikke ~undo~ to gange i træk. Beklager!]";
        13: "[Foregående træk er fortrudt.]";
        14: "Beklager, men det kan ikke gøres om.";
        15: "Det var da så lidt.";
        16: "~Oops~ can only correct a single word.";
        17: print "Det ";
            Tense("er", "var");
            print " bælgmørkt, og ", (theActor) actor;
            Tense(" kan ikke", " kunne ikke");
            " se en pind.";
        18: print "dig selv";
        19: "Lige så nydelig som altid.";
        20: "For at gentage en kommando som ~frø, hop~, skriv bare ~igen~, ikke ~frø, igen~.";
        21: CSubjectCan(actor,true); " næppe gentage det.";
        22: CSubjectCant(actor, true); " begynde en ytring med et komma.";
        23: CSubjectVerb(actor, true, false, "ser ud til", "ser ud til", "ser ud til", "så ud til");
            print " at ville tale med nogen, men jeg ";
            Tense("kan", "kunne"); " ikke se hvem.";
        24: CSubjectCant(actor, true); " tale med ", (the) x1, ".";
        25: "For at tale med nogen, prøv ~person, hej~ eller ligende.";
        26: "(tager først ", (the) x1, ")";
        27: "Den ytring forstod jeg ikke.";
        28: print "Hvis jeg forstod dig ret, så tror jeg at du ville ";
        29: "Det tal forstod jeg ikke.";
        30: CSubjectCant(actor,true); " se noget sådant her.";
        31: CSubjectVerb(actor, true, false, "ser ud til", "ser ud til", "ser ud til", "så ud til");
            " at have sagt for lidt!";
        32: CSubjectIsnt(actor); " har det ikke!";
        33: "Du kan ikke bruge det udsagnsord på flere ting.";
        34: "Du kan kun nævne flere ting én gang per linje.";
        35: "Jeg er ikke sikker på hvad ~", (address) x1, "~ refererer til.";
        36: "Du udelod noget som alligevel ikke var med!";
        37: CSubjectCan(actor,true); " kun gøre det ved noget levende.";
            #Ifdef DIALECT_US;
        38: "Det verbum kender jeg ikke.";
            #Ifnot;
        38: "Det verbum kender jeg ikke.";
            #Endif;
        39: "Det er ikke noget, du har brug for i dette spil.";
        40: CSubjectCant(actor,true); " se ~", (address) x1, "~ (", (the) x2, ") i øjeblikket.";
        41: "Jeg forstod ikke rigtig den afslutning.";
        42: if (x1 == 0) print "Ingen"; else print "Kun ", (number) x1;
            print " af dem ";
            if (x1 == 1) print "er"; else print "er";
            " tilgængelige.";
        43: "Ingenting at gøre!";
        44: print "Der ";
            Tense("er", "var");
            " ingenting ", (address) x1, ".";
        45: print "Hvad mener du med, ";
        46: print "Mener du, ";
        47: "Beklager, men du kan kun have én ting her. Hvilken?";
        48: print "Hvem ";
            CSubjectVerb(player, false, true, "vil", "vil", "vil", "ville");
            if (x1 ~= player && x1 ~= nothing) print " ", (the) x1;
            print " til "; PrintCommand(); "?";
        49: print "Hvad ";
            CSubjectVerb(player, false, true, "vil", "vil", "vil", "ville");
            if (x1 ~= player && x1 ~= nothing) print " ", (the) x1;
            print " til "; PrintCommand(); "?";
        50: print "Score er lige gået ";
            if (x1 > 0) print "op"; else { x1 = -x1; print "ned"; }
            print " med ", (number) x1, " point";
            if (x1 > 1) print "s";
        51: "(Eftersom noget dramatisk er sket, er din liste med kommandoer blevet afkortet.)";
        52: "^Skriv et tal mellem 1 og ", x1, ", 0 for at vise dette igen eller tryk ENTER.";
        53: "^[Tryk SPACE.]";
        54: "[Comment recorded.]";
        55: "[Comment NOT recorded.]";
        56: ".";
        57: "?";
        58: "(tager først ", (the) x1, " ", (nop) SupportObj(x2,"af","ud af"), " ", (the) x2, ")";
        59: "Du må være mere specifik.";
        60: print (The) x1, " observerer at ";
    }
  No,Yes:   "Det var et retorisk spørgsmål.";
  NotifyOff:
            "Score notification off.";
  NotifyOn: "Score notification on.";
  Objects: switch (n) {
        1:  "Objekter du ", (nop) CSubjectVerb(actor, false, true, "har", "har", "havde"), " benyttet:^";
        2:  "Ingen.";
        3:  print "   (båret)";
        4:  print "   (holdt)";
        5:  print "   (givet væk)";
        6:  print "   (i ", (name) x1, ")";
        7:  print "   (i ", (the) x1, ")";
        8:  print "   (indeni ", (the) x1, ")";
        9:  print "   (på ", (the) x1, ")";
        10: print "   (mistet)";
    }
  Open: switch (n) {
        1:  CSubjectIs  (x1,true);
            print " er ikke noget som ", (theActor) actor;
            Tense(" kan åbne", " kunne have åbnet");
            ".";
        2:  CSubjectVerb(x1,true,false,"virker",0,"virker","virkede"); " låst.";
        3:  CSubjectIs  (x1,true); " allerede åben.";
        4:  CSubjectVerb(actor,false,false,"åbner",0,"åbner","åbnede"); print " ", (the) x1;
            Tense(", og finder ", " og fandt ");
                if (WriteListFrom(child(x1), ENGLISH_BIT+TERSE_BIT+CONCEAL_BIT) == 0) "ingenting.";
                ".";
        5:  CSubjectVerb(actor,false,false,"åbner",0,"åbner","åbnede"); " ", (the) x1, ".";
        6:  "(åbner først ", (the) x1, ")";
    }
  Order:    CSubjectHas(x1,false); " har vigtigere ting at gøre.";
  Places: switch (n) {
        1:  print "Du har besøgt: ";
        2:  ".";
    }
  Pray:     print "Intet brugbart ";
            Tense("kommer", "kom");
            " ud af ", (Possessive) actor, " bøn.";
  Prompt:   print "^>";
  Pronouns: switch (n) {
        1:  print "Akurat nu, ";
        2:  print "betyder ";
        3:  print "er fravalgt";
        4:  "ingen pronomener er kendt for dette spil.";
        5:  ".";
    }
  Pull,Push,Turn: switch (n) {
        1:  if (player provides narrative_voice && player.narrative_voice == 3) {
                print_ret (The) player, " ", (nop) Tense("er ikke", "var ikke"),
                  " i stand til at skubbe ",
                              (OnesSelf) player, " den vej.";
            } else {
                "At skubbe ", (OnesSelf) player, " den vej ",
                              (nop) Tense("er ikke", "var ikke"), " i stand til at hjælpe på sagen.";
            }
        2:  CSubjectIs  (x1,true); " sidder fast.";
        3:  CSubjectIs  (actor,true); " ude af stand til.";
        4:  print "Intet åbentlyst ";
            Tense("sker", "skete");
            ".";
        5:  print "Det ville ";
            Tense("være", "have været");
            " intet mindre end uhøfligt.";
        6:  DecideAgainst();
    }
! Push: see Pull
  PushDir: switch (n) {
        1:  print "Det ";
            Tense("vil", "ville");
            " virkelig ikke have noget formål.";
        2:  print "Det ";
            Tense("er", "er");
            " ikke en retning.";
        3:  print "Det går nok ikke i den retning ", (theActor) actor;
            Tense("", "");
            ".";
    }
  PutOn: switch (n) {
        1:  CSubjectVerb(actor,true,false,"må",0,"må","måtte");
            print " holde ", (the) x1, " før ", (theActor) actor;
            Tense(" kan", " kunne");
            " lægge ", (ItOrThem) x1, " på noget.";
        2:  CSubjectCant(actor,true,true); " lægge noget på sig selv.";
        3:  print "At lægge ting på ", (the) x1, " ville";
            Tense(" ikke medføre", " ikke have medført");
            " noget.";
        4:  CSubjectVerb(actor,true,false,"mangler",0,"mangler","manglede"); " smidighed.";
        5:  "(tager først ", (ItOrThem) x1, " af)";
        6:  print "Der ";
            Tense("er", "var");
            " ikke mere plads på ", (the) x1, ".";
        7:  "Udført.";
        8:  CSubjectVerb(actor,false,false,"lægger",0,"lægger","lagde"); " ", (the) x1, " på ", (the) x2, ".";
    }
  Quit: switch (n) {
        1:  print "Svar ja eller nej.";
        2:  print "Er du sikker på, at du vil afslutte? ";
    }
  Remove: switch (n) {
        1:  CSubjectIs  (x1,true); " desværre lukket.";
        2:  print "Men ";
            CSubjectIsnt(x1,true); " der nu.";
        3:  "Fjernet.";
    }
  Restart: switch (n) {
        1:  print "Er du sikker på at du vil genstarte? ";
        2:  "Genstart fejlede.";
    }
  Restore: switch (n) {
        1:  "Hentning af spil fejlede.";
        2:  "Ok.";
    }
  Rub: switch (n) {
        1:  CSubjectVerb(actor,true,false,"opnår",0,"opnår","opnåede");
            " ingenting ved dette.";
        2:  DecideAgainst();
    }
  Save: switch (n) {
        1:  "Gemning af spillet fejlede.";
        2:  "Ok.";
    }
  Score: switch (n) {
        1:  if (deadflag) print "I dette spil fik du "; else print "Du har scoret ";
                print score, " point ud af ", MAX_SCORE, " mulige i ", turns, " træk";
                return;
        2:  "Der er ingen point i dette spil.";
    }
  ScriptOff: switch (n) {
        1:  "Transcripting is already off.";
        2:  "^End of transcript.";
        3:  "Attempt to end transcript failed.";
    }
  ScriptOn: switch (n) {
        1:  "Transcripting is already on.";
        2:  "Start of a transcript of";
        3:  "Attempt to begin transcript failed.";
    }
  Search: switch (n) {
        1:  print "Men det";
            Tense(" er", " var");
            " mørkt.";
        2:  print "Der ";
            Tense("er", "var");
            " ingenting på ", (the) x1, ".";
        3:  print "På ", (the) x1;
                WriteListFrom(child(x1), ENGLISH_BIT+TERSE_BIT+CONCEAL_BIT+ISARE_BIT);
                ".";
        4:  CSubjectVerb(actor,true,false,"finder",0,"finder","fandt"); " ingenting af interesse.";
        5:  CSubjectCant(actor,true); " se indeni, eftersom ", (the) x1, " ", (IsOrAre) x1, " lukket.";
        6:  "", (The) x1, " ", (IsOrAre) x1, " tom.";

        7:  print "I ", (the) x1;
                WriteListFrom(child(x1), ENGLISH_BIT+TERSE_BIT+CONCEAL_BIT+ISARE_BIT);
                ".";
    }
   ! Preceding "No," unable to be used for Set and SetTo
  Set:      CSubjectCant(actor,true); " sæt ", (ThatOrThose) x1, ".";
  SetTo:    CSubjectCant(actor,true); " sætte ", (ThatOrThose) x1, " til noget.";
  Show: switch (n) {
        1:  CSubjectIsnt(actor,true); " holder ", (the) x1, ".";
        2:  CSubjectIs  (x1,true); " ikke imponerende.";
    }
  Sing:     print (PossessiveCaps) actor, " ";
            Tense("har", "havde");
            " ikke meget af en sangstemme";
  Sleep:    CSubjectIsnt(actor,true); " særlig søvning.";
  Smell: switch (n) {
        1:  CSubjectVerb(actor,true,false,"lugter",0,"lugter","lugtede"); " ikke noget uventet.";
        2:  DecideAgainst();
    }
            #Ifdef DIALECT_US;
  Sorry:    "Lad gå for denne gang.";
            #Ifnot;
  Sorry:    "Lad gå for denne gang.";
            #Endif;
  Squeeze: switch (n) {
        1:  DecideAgainst();
        2:  CSubjectVerb(actor,true,false,"opnår",0,"opnår","opnåede"); " ikke noget ved dette.";
    }
  Strong:   print "Ægte eventyrere ";
            Tense ("taler", "talte");
            " ikke sådan.";
  Swim:     print "Der ";
            Tense("er ikke", " var ikke");
            " nok vand at svømme i.";
  Swing:    print "Der ";
            Tense("er", "var");
            " inget fornuftigt at svinge sig i her.";
  SwitchOff: switch (n) {
        1:  CSubjectIs  (x1,true);
            print " ikke noget ", (theActor) actor, " ";
            Tense("kan", "kunne");
            " skrue af eller på.";
        2:  CSubjectIs  (x1,true); " allerede slukket.";
        3:  CSubjectVerb(actor,false,false,"slukker",0,"slukker","slukkede"); " ", (the) x1, ".";
    }
  SwitchOn: switch (n) {
        1:  CSubjectIs  (x1,true);
            print " ikke noget ", (theActor) actor, " ";
            Tense("kan", "kunne");
            " skrue af eller på.";
        2:  CSubjectIs  (x1,true); " allerede tændt.";
        3:  CSubjectVerb(actor,false,false,"tænder",0,"tænder","tændte"); " ", (the) x1, " .";
    }

  Take: switch (n) {
        1:  "Taget.";
        2:  CSubjectIs  (actor,false); " har altid været lidt selvoptaget.";
        3:  print "Jeg tror ikke ", (the) x1, " ville ";
            Tense("synes", "have synes");
            " om det.";
        4:  CSubjectWill(actor,true);
            Tense(" må ", " måtte ");
            " tage ", (nop) SupportObj(x1,"af","ud af"), " ", (the) x1, " først.";
        5:  CSubjectVerb(actor,true,false,"har allerede",0,"har allerede","havde allerede"); " ", (ThatOrThose) x1, ".";
        6:  CSubjectVerb(x2,true,false,"ser ud",0,"ser ud","så ud"); " til at tilhøre ", (the) x1, ".";
        7:  CSubjectVerb(x2,true,false,"ser ud",0,"ser ud","så ud"); " til at være en del af ", (the) x1, ".";
        8:  CSubjectIs  (x1,true); " ikke tilgængelig.";
        9:  CSubjectIs  (x1,true); " ikke åben.";
        10: CSubjectIs  (x1,true); " knapt bærbar.";
        11: CSubjectIs  (x1,true); " sidder fast.";
        12: CSubjectIs  (actor,true); " bærer på for mange ting allerede.";
        13: "(lægger ", (the) x1, " ind i ", (the) x2, " for at gøre plads)";
    }
  Taste: switch (n) {
        1:  CSubjectVerb(actor,true,false,"smager",0,"smager","smagte"); " intet uventet.";
        2:  DecideAgainst();
    }
  Tell: switch (n) {
        1:  CSubjectVerb(actor,false,false,"taler",0,"taler","talte");
            " til ", (OnesSelf) actor, " et lille stykke tid.";
        2:  print "Dette ";
            Tense("frembringer", "frembragte");
            " ingen reaktion.";
    }
  Think:    "Det var en god idé.";
  ThrowAt: switch (n) {
        1:  "Meningsløst.";
        2:  CSubjectVerb(actor,true,false,"mangler",0,"mangler","manglede");
            print " mod til det ";
            Tense("når det kommer", "da det kom");
            " til stykket.";
    }
  Tie: switch (n) {
        1:  CSubjectVerb(actor,true,false,"ville",0,0);
            Tense(" opnår", " have opnået");
            " intet ved at gøre dette.";
        2:  DecideAgainst();
    }
  Touch: switch (n) {
        1:  DecideAgainst();
        2:  CSubjectVerb(actor,true,false,"føler",0,"føler","følte"); " intet uventet.";
        3:  print "Det ";
            Tense("vil", "ville");
            " virkelig ikke have noget formål.";
    }
! Turn: see Pull.
  Unlock:  switch (n) {
        1:  CSubjectDont(x1,true);
            print " ser ikke ud til at være noget, ", (theActor) actor;
            Tense(" kan låse op", " kunne låse op");
            ".";
        2:  CSubjectIs  (x1,true); " ulåst i øjeblikket.";
        3:  CSubjectDont(x1,true); " ser ud til at passe i låsen.";
        4:  CSubjectVerb(actor,false,false,"låser",0,"låser","låste"); " ", (the) x1, " op.";
        5:  "(låser føst ", (the) x1, " op)";
    }
  VagueGo:  CSubjectWill(actor);
            print " må ";
            Tense("", " måtte ");
            "sige hvilken kompasretning at gå i.";
  Verify: switch (n) {
        1:  "The game file has verified as intact.";
        2:  "The game file did not verify as intact, and may be corrupt.";
    }
  Wait:     print "Tiden ";
            Tense("går", "gik");
            ".";
  Wake:     print "Dette ";
            Tense("er", "var");
            " desværre ikke en drøm.";
  WakeOther:print "Det ";
            Tense("virker", "virkede");
            " unødvendigt.";
  Wave: switch (n) {
        1:  print "Men ";
            CSubjectIsnt(actor,true,true); " bærer ikke ", (ThatOrThose) x1, ".";
        2:  CSubjectVerb(actor,false,false,"ser",0,"ser","så");
            print " fjollet ud, som du vifter med ", (the) x1;
            if (x2)
                " mod ", (the) x2, ".";
            ".";
        3:  DecideAgainst();
    }
  WaveHands:
        CSubjectVerb(actor,false,false,"vinke",0,"vinke","vinkede");
        switch (n) {
        1: ! nothing
        2: print " til ", (the) x1;
        }
        ", og føler dig lidt fjollet.";
  Wear: switch (n) {
        1:  CSubjectCant(actor,true); " bærer ", (ThatOrThose) x1, "!";
        2:  CSubjectIs  (actor,true); " holder ikke ", (ThatOrThose) x1, "!";
        3:  CSubjectIs  (actor,true); " bærer allerede ", (ThatOrThose) x1, "!";
        4:  CSubjectVerb(actor,false,false,"tager",0,"tager","tog"); " ", (the) x1, " på.";
    }
! Yes:  see No.
];

! ==============================================================================

Constant LIBRARY_ENGLISH;       ! for dependency checking.
#Endif;

! ==============================================================================
