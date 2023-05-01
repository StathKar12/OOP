Καραγιάννης Ευστάθιος sdi1800311(1115201800311)

Η Εργασια 3 αποτελειται απο 7 αρχεια:
	Makefile:
		run:Object
			Object
		Object:main.o
			g++ main.o -o Object
		main.o:main.cpp Plane_class.h
			g++ -c main.cpp
		clean:
			rm -f Object main.o
	Το Makefile χρησιμοποιειται για την δημιουργια του εκτελεσιμου αρχειου "Object".
	main.cpp:
		Στην main ακολουθουνται οι οδηγιες της εκφώνησης και αρχικοποιει την srand.
		Και χρησιμοποιει τα αρχεια:
			Object_class.h
			String_class.h
			Employees_class.h
			PlaneComponent_class.h
			Plane_class.h
	Object_class.h:
		Στο αρχειο αυτο ειναι υλοποιημενη η Object(class).
		Αποτελειται απο τις functions που αναφέρονται στην εκφώνηση. 
		Επιπλεον περιεχει και την function gen_id() η οποια δημιουργει ενα μοναδικο ID
		και το εκχωρει στο id της Object.
		To id και η gen_id() ειναι protected για να ειναι ορατα και απο τις κλασσεις που
		κληρονομουν απο την Object.
	String_class.h:
		Στο αρχειο αυτο ειναι υλοποιημενη η String(class).
		Αποτελειται απο τις functions που αναφέρονται στην εκφώνηση.
		Ορισμένες functions ειναι Overloaded για λογους διευκολυνσης.
		Η Function print() δέχεται 2 επιπλέων ορισματα που βοηθουν στην 
		εμφανηση της String(class).
	 Employees_class.h:
		Στο αρχειο αυτο ειναι υλοποιημενη η Employees(class),SecurityEmployee(class),
		MaintenanceEmployee(class),CleaningEmployee(class).
		Οι οποιες αποτελουνται απο τις functions που αναφέρονται στην εκφώνηση.
		Για την υλοποιηση της report() δημιουργησα εναν τυπο, τον work_on_ με enum,
		ο οποιος περιγραφει τον χωρο τον οποιο βρησκεται ο Employee ετσι ωστε να
		εμφανιζονται τα καταλληλα μηνυματα.
		Η workOn() χρησιμοποιει τον τυπο work_on_ για τον ιδιο λογο και επιπλεον 
		παιρνει ως ορισμα εναν String& το οποιο αποθηκευει τις δουλειες που εχουν γινει.
	 PlaneComponent_class.h:
		Στο αρχειο αυτο ειναι υλοποιημενη η PlaneComponent(class),PassengerCompartment(class),
		PrivateCompartment(class),EquipmentCompartment(class),CargoBay(class).
		Οι οποιες αποτελουνται απο τις functions που αναφέρονται στην εκφώνηση.
		To String works_done αποθηκευει πληροφοριες για το ποιες δουλειες εχουν γινει, απο
		ποιον Employee.
		works_done (SecurityEmployee, MaintenaceEmployee , CleaningEmployee).
		Στην process καθε φορα που δουλευει ενας employee κανει αμεσος μετα την δουλεια του
		και ενα report.
		Και η ready_check() σε περιπτωση που εχουν γινει ολες οι απαραιτητες δουλειες
		απο τους Employees εμφανιζει για καθε Compartment και Cargo Bay το καταλληλο μηνυμα.
		Επιπλεον περιλαμβανει 1 global μεταβλητες:
			Sub_PassengerCompartment_Producing_Probability.
			Η οποια εχει ως default τιμη το 1 αλλα μπορει να αλλαχθει απο τον χρηστη
			για λογους δοκιμων.
			Η μεταβλητη αυτη μεταβαλλει την πιθανοτητα δημιουργιας SubPassengerCompartment
			κατα την δημιουργια ενος PassengerCompartment.
			Οταν εχει την Default τιμη της εχουμε παντα 1 SubPassengerCompartment.
	 Plane_class.h:
		Στο αρχειο αυτο ειναι υλοποιημενη η Plane(class) και η function 
		clone_encrypt_and_print().
		Η Plane(class) αποτελειται απο τις functions που αναφέρονται στην εκφώνηση.
		Και η clone_encrypt_and_print() ακολουθει τις οδηγειες της εκφωνησης.
		Επιπλεον περιλαμβανει 2 global μεταβλητες:
			(Α)Max_Plane_Capacity,
			(Β)Max_Passnger_Compartment_Capacity.
			Οι οποιες εχουν μια default τιμη αλλα μπορουν να αλλαχθουν απο τον χρηστη
			για λογους δοκιμων.
			Οι μεταβλητες αυτες απεικονιζουν (Α) την χωρητικοτητα του Αεροπλανου και 
			(Β) την χωρητικοτητα ενος Passenger Compartment του Αεροπλανου
		Οι functions ready_check(), process() εχουν την ιδια λειτουργια με αυτην που εχει
		προαναφερθει.