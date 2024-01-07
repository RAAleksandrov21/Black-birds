import React from "react";
import {
  SafeAreaView,
  StyleSheet,
  StatusBar,
  Platform,
  TextInput,
} from "react-native";

function Register() {
  return (
    <SafeAreaView style={styles.container}>
      <TextInput
        style={styles.input}
        placeholder="First name"
        textContentType="name"
        placeholderTextColor={"white"}
      />
      <TextInput
        style={styles.input}
        placeholder="Second name"
        textContentType="name"
        placeholderTextColor={"white"}
      />
      <TextInput
        style={styles.input}
        placeholder="Last name"
        textContentType="name"
        placeholderTextColor={"white"}
      />
      <TextInput
        style={styles.input}
        placeholder="Email name"
        textContentType="emailAddress"
        placeholderTextColor={"white"}
      />
      <TextInput
        style={styles.input}
        placeholder="Password"
        textContentType="password"
        placeholderTextColor={"white"}
      />
      <TextInput
        style={styles.input}
        placeholder="Username"
        textContentType="username"
        placeholderTextColor={"white"}
      />
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: Platform.OS === "android" ? StatusBar.currentHeight : 0,
    backgroundColor: "dodgerblue",
    alignItems: "center",
  },
  input:{
    height:40,
    margin: 20,
    borderWidth:1,
    padding:10,
    width:"50%",
    borderColor:"white"
  },
});

export default Register;
