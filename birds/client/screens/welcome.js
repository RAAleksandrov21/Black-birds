import React from 'react'
import {
  ImageBackground,
  SafeAreaView,
  StyleSheet,
  View,
  Text,
  Image,
  Platform,
  StatusBar,
  Button,
  TouchableOpacity
} from "react-native";

function WelcomeScreen({navigation}) {
  
  
  return (
    <View style={styles.container}>
      <Text style={styles.infoText}>
        Hi, we are Beck!{"\n"}We are here{"\n"}to help you{"\n"}to will propely!
      </Text>
      <TouchableOpacity
        style={styles.regButton}
        onPress={() => navigation.navigate("Register")}
      >
        <Text style={styles.infoButton}>Next</Text>
      </TouchableOpacity>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: Platform.OS === "android" ? StatusBar.currentHeight : 0,
    backgroundColor: "#00010D",
    justifyContent: "center",
  },
  regButton: {
    backgroundColor: "rgba(255, 8, 245, 0.34)",
    padding: 10,
    alignItems: "center",
    borderRadius: 50,
    width: 100,
    bottom: 20,
    position: "absolute",
    right: 20,
  },
  infoText: {
    textAlign: "center",
    fontSize: 60,
  },
  infoButton:{
    fontSize:18
  }
});


export default WelcomeScreen;
