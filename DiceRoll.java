import java.util.Scanner;
public class DiceRoll {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int seed; //seed to be used for special round.
	char character = 'r'; //character input for dice roll;
	int total = 0; // total of dice rolls;
	int dice1 = 0;//first dice roll;
	int dice2 = 0; //second dice roll;
	long numOfWins = 0; //number of wins recorded;
	long numOfLosses = 0; //number of losses recorded;
	int target = 0; //target for second round;
	long numOfRounds = 0;
	long numOfSpecial = 0;
	System.out.println("Welcome to the Dice Roll Challenge.  Attempt to roll the dice against one of the toughest random number challenges there is!");
	System.out.println("Enter a lucky number: ");
	seed = input.nextInt();
	if ((seed <= 0) ^ (seed >=12)) {
		seed = (int)(Math.random() * 7);
		System.out.println("The seed has been reset to a random value.");
	}
	else {
		System.out.println(seed + " is the seed used.  Seed saved.");
	}
	while (character == 'r') { //while(character entetred == 'r') {
		System.out.println("Enter r to roll, or q to stop.");
		character = input.next().charAt(0); //enter a character;
		if (character == 'r') { //if(character entered == 'r') {
			dice1 = roll(); //roll dice; save roll to first die;
			System.out.println("The first die roll is: " + dice1);
			total = total + dice1; //add dice roll to total;
			dice1 = 0;
			dice2 = roll(); //roll dice again; save roll to second die; }
			System.out.println("The second die roll is " + dice2);
			total = total + dice2;
			dice2 = 0;
		}
		else if (character == 'q') { //else if (character entered == 'q') {
			quit(numOfWins, numOfLosses, numOfRounds, numOfSpecial); //quit;
		}
		if (total == 7 || total == target) {//if(total == 7) {
			numOfWins++;
			numOfRounds++;
			displayWin(numOfWins, numOfLosses, numOfRounds, numOfSpecial); // player wins!;  display current results; }
		}
		else if ((total == 2) ^ (total == 3) ^ (total == 12)) { //else if(total of dice rolls == 2 XOR 3 XOR 12) {
			numOfLosses++;
			numOfRounds++;
			displayLoss(numOfLosses, numOfWins, numOfRounds, numOfSpecial); //player loses...; display current results; }
		}
		else if ((total == 4) ^ (total == 5) ^ (total == 6) ^ (total == 8) ^ (total == 9) ^ (total == 10)) { //else if(total == 5 XOR 6 XOR 8 XOR 9 XOR 10) {
			target = total;
			total = 0;
			System.out.println("You rolled a special value!  Roll it again to win.  (In the JAVA version, your seed is only taken into account in the Special Rounds)"); //special value rolled!;
				
				while (total != target) { //continue to roll until total == target value;
					System.out.println("Enter r to roll, or q to stop");
					character = input.next().charAt(0);
					if (character == 'r') {
						dice1 = roll();
						System.out.println("The first die roll is " + dice1);
						total = total + dice1;
						dice1 = 0;
						dice2 = roll();
						System.out.println("The second die roll is " + dice2);
						total += dice2;
						if(numOfLosses > numOfWins) {
							if(total + seed <= 12) {
								System.out.println("Seed bonus applied!  Your total was successfully increased by " + seed);
								total += seed;
							}
							else {
								System.out.println("Oof...  Your seed, " + seed + " was unable to be appled.  Corresponding result too high!");
							}
						}
						dice2 = 0;
					}
					else if (character == 'q') {
						quit(numOfWins, numOfLosses, numOfRounds, numOfSpecial);
					}
					if (total == 7) {
						numOfLosses++;
						numOfRounds++;
						numOfSpecial++;
						displayLoss(numOfLosses, numOfWins, numOfRounds, numOfSpecial);
						break;
					}
					if (total == target) {
						numOfWins++;
						numOfRounds++;
						numOfSpecial++;
						displayWin(numOfWins, numOfLosses, numOfRounds, numOfSpecial);
						break;
					}
					total = 0;

					
				}
				
		}
		total = 0;
	}
}


	public static void displayWin(long numOfWins, long numOfLosses, long numOfRounds, long numOfSpecial) {
		System.out.println("Congratulations!  You win!");
		System.out.println("---------------");
		System.out.println("current wins = " + numOfWins + ".  current losses = " + numOfLosses + ". Number of Rounds = " + numOfRounds + ".  Number of Special rounds = " + numOfSpecial);
		return;
	}
	public static void displayLoss(long numOfLosses, long numOfWins, long numOfRounds, long numOfSpecial) {
		System.out.println("Sorry... You lose.");
		System.out.println("----------------");
		System.out.println("current wins = " + numOfWins + ".  current losses = " + numOfLosses + ". Number of Rounds = " + numOfRounds + ".  Number of Special rounds = " + numOfSpecial);
		return;
	}
	public static void quit(long numOfWins, long numOfLosses, long numOfRounds, long numOfSpecial) {
		int numOfRolls = 0;
		int nextRoll = 0;
		long numOf1 = 0;
		long numOf2 = 0;
		long numOf3 = 0;
		long numOf4 = 0;
		long numOf5 = 0;
		long numOf6 = 0;
		System.out.println("The final results are: number of wins = " + numOfWins + ", number of losses = " + numOfLosses + ", number of Rounds = " + numOfRounds + ", number of Special rounds = " + numOfSpecial);
		while (numOfRolls < 60000) {
			nextRoll = roll();
			switch (nextRoll) {
			case 1: numOf1++; break;
			case 2: numOf2++; break;
			case 3: numOf3++; break;
			case 4: numOf4++; break;
			case 5: numOf5++; break;
			case 6: numOf6++; break;
			}
			numOfRolls++;
		}
		System.out.println("Number of ones rolled is " + numOf1);
		System.out.println("Number of twos rolled is " + numOf2);
		System.out.println("Number of threes rolled is " + numOf3);
		System.out.println("Number of fours rolled is " + numOf4);
		System.out.println("Number of fives rolled is " + numOf5);
		System.out.println("Number of sixes rolled is " + numOf6);
		System.exit(0);


	}
	private static int roll() {
		int dice = (int)((Math.random() * 6) + 1);
		return dice;
	}

	
	
}