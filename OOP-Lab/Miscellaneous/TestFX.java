import javafx.application.*;
import javafx.event.*;
import javafx.scene.*;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.*;
import javafx.geometry.*;

public class TestFX extends Application{
    Label response;
    public static void main(String[] args) {
        launch(args);
    }

    public void start(Stage myStage) {
        primaryStage.setTitle("Demonstrate JavaFX Buttons and Events.");

        FlowPane rootNode = new FlowPane(10,10);
        rootNode.setAlignment(Pos.CENTER);

        Scene myScene = new Scene(rootNode, 300, 100);
        myStage.setScene(myScene);

        response = new Label("Push a Button");
        Button btnAlpha = new Button("Alpha");
        Button btnBeta = new Button("Beta");


        btnAlpha.setOnAction(new EventHandler<ActionEvent>() {

            public void handle(ActionEvent ae) {
                response.setText("Alpha was pressed");
            }
        });

        btnBeta.setOnAction(new EventHandler<ActionEvent>() {

            public void handle(ActionEvent ae) {
                response.setText("Beta was pressed");
            }
        });


        rootNode.getChildren().addAll(btnAlpha, btnBeta, response);
        
        myStage.show();
    }
}