import React, {useState} from "react";
import {
  ImageBackground,
  SafeAreaView,
  StyleSheet,
  View,
  Platform,
  StatusBar,
  TextInput,
  TouchableOpacity,
  Text,
} from "react-native";
import { Button } from "react-native-paper";
import * as DocumentPicker from "expo-document-picker";

function Create({ navigation }) {

  const [title,setTitle] = useState("");
  const[body, setBody] = useState("");


  const selectDoc = async() =>{
    
    try{
      const doc = await DocumentPicker.getDocumentAsync();
      if(doc.type === "success"){
        console.log(doc)
      }
      else{
        console.log("User canceled the upload")
      }
      console.log(doc)
    }
    catch(err){
      console.log(err)
    }
  }


  return (
    <View style={styles.container}>
      <TextInput
        style={styles.input}
        label="Title"
        value={title}
        mode="outlined"
        placeholder="Text"
        placeholderTextColor={"white"}
        onChangeText={(text) => setTitle(text)}
      />
      <TextInput
        style={styles.inputBody}
        styles={{ height: 100 }}
        label="Description"
        value={body}
        mode="outlined"
        placeholder="Text"
        placeholderTextColor={"white"}
        multiline
        numberOfLines={40}
        onChangeText={(text) => setBody(text)}
      />

      <Button 
      icon={"pencil"} 
      mode="contained"
      style={styles.writeButton} 
      onPress={() => {}} 
      >Insert will </Button>
      <TouchableOpacity
        
        onPress={selectDoc}
        style={styles.pickDocsButton}
      >
        <Text>Select document</Text>
      </TouchableOpacity>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: Platform.OS === "android" ? StatusBar.currentHeight : 0,
    backgroundColor: "#00010D",
    alignItems: "center",
  },
  input: {
    height: 40,
    margin: 20,
    borderWidth: 1,
    padding: 10,
    width: "70%",
    borderColor: "white",
    borderRadius: 50,
    fontSize: 16,
    width: "90%",
  },
  inputBody: {
    height: 40,
    margin: 20,
    borderWidth: 1,
    padding: 10,
    width: "70%",
    borderColor: "white",
    borderRadius: 0,
    fontSize: 16,
    height: 100,
    width: "90%",
  },
  pickDocsButton: {
    marginTop: 20,
    backgroundColor: "blue",
    borderRadius: 10,
    padding: 10,
  },
  writeButton: {
    width: "90%",
  },
});

export default Create;
