void boilWater() {
    printf("Step 1 Boil 2 cups of water.\n");
}

void addNoodles() {
    printf("Step 2 Add noodles to the boiling water.\n");
}

void stirNoodles() {
    printf("Step 3 Stir the noodles gently for 3 minutes.\n");
}

void addSeasoning() {
    printf("Step 4 Add seasoning packet to the noodles. Stir well.\n");
}

void serve() {
    printf("Step 5 Turn off heat and serve hot.\n");
}

int main() {
    printf("Instant Noodles Recipe\n");
    printf("Ingredients Instant noodles, water, seasoning packet.\n\n");

    boilWater();
    addNoodles();
    stirNoodles();
    addSeasoning();
    serve();

    printf("\nEnjoy your meal! (And don't burn yourself!)\n");
    return 0;
}
