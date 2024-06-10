module test_group {
    requires javafx.controls;
    requires javafx.fxml;

    opens test_group to javafx.fxml;
    exports test_group;
}
